import requests
import csv
from concurrent.futures import ThreadPoolExecutor

# Constants
COUNTRY_CODES = ["RUS"]  # List of country codes
INDICATORS = {
    "GDP Growth": "NY.GDP.MKTP.KD.ZG",
    "Unemployment": "SL.UEM.TOTL.ZS",
    "Inflation (CPI)": "FP.CPI.TOTL.ZG",
    "Gov Debt": "GC.DOD.TOTL.GD.ZS",
    "Current Account Balance": "BN.CAB.XOKA.GD.ZS",
    "FDI Net Inflows": "BX.KLT.DINV.CD.WD",
    "PPP Conversion Factor": "PA.NUS.PPP"
}
BASE_URL = "http://api.worldbank.org/v2/country"
START_YEAR = 2000
END_YEAR = 2021
CSV_FILENAME = "world_bank_data.csv"

# Function to make API requests and fetch data
def fetch_data(country_code, indicator_code):
    url = f"{BASE_URL}/{country_code}/indicator/{indicator_code}?format=json&date={START_YEAR}:{END_YEAR}"
    print("Fetching data from URL:", url)  # Log the URL being requested
    response = requests.get(url)
    if response.status_code == 200:
        return response.json()
    else:
        print(f"Failed to fetch data for {country_code} and {indicator_code}. Status code:", response.status_code)
        return None

# Function to write data to CSV
def write_to_csv(country_code, indicator_name, data):
    with open(CSV_FILENAME, 'a', newline='') as csvfile:
        writer = csv.writer(csvfile)
        for entry in data[1]:
            year = entry['date']
            value = entry['value']
            writer.writerow([country_code, indicator_name, year, value])
    print(f"Data for {country_code} - {indicator_name} written to {CSV_FILENAME}")

def main():
    # Write CSV header
    with open(CSV_FILENAME, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Country Code', 'Indicator', 'Year', 'Value'])

    with ThreadPoolExecutor() as executor:
        futures = []
        for country_code in COUNTRY_CODES:
            for indicator_name, indicator_code in INDICATORS.items():
                futures.append(executor.submit(fetch_data, country_code, indicator_code))
        for future in futures:
            result = future.result()
            if result:
                print("Result:", result)  # Debugging print
                if len(result) > 1 and result[1]:
                    country_code = result[1][0].get('countryiso3code', 'N/A')
                    indicator_name = result[1][0]['indicator'].get('value', 'N/A')
                    write_to_csv(country_code, indicator_name, result)
                else:
                    print("Result data structure is not as expected or is empty.")
            else:
                print("No result received from the API.")

if __name__ == "__main__":
    main()



# SWE;FIN;FRA;ESP;LTU;EST;RUS;USA;CAN;MEX;BRA;PER;ARG;CHN;JPN;VNM;DZA;NAM;EGY;KAZ".split(';')