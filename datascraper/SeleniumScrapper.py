from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.options import Options
import time
import zipfile
import csv
import mysql.connector
from mysql.connector import Error

def insert_into_database(name, price, source, currency):
    connection = None
    db_cursor = None
    try:
        price = float(price.replace('$', ''))

        connection = mysql.connector.connect(
            host='localhost',
            database='scrapingdb',
            user='root',
            password='PechkaKrasava'
        )
        if connection.is_connected():
            db_cursor = connection.cursor()
            query = """
            INSERT INTO products (name, price, source, currency)
            VALUES (%s, %s, %s, %s)
            """
            db_cursor.execute(query, (name, price, source, currency))
            connection.commit()
            print("Query executed successfully")
            return "Inserted successfully"
    except Error as e:
        return f"Error: {e}"
    finally:
        if db_cursor:
            db_cursor.close()
        if connection and connection.is_connected():
            connection.close()

# Set up the Selenium browser
options = Options()
options.headless = True  # No need for a GUI
service = Service(ChromeDriverManager().install())
options.add_argument("--headless")  # Ensures Chrome runs in headless mode
options.add_argument("--disable-gpu")  # Disables GPU hardware acceleration
options.add_argument("--no-sandbox")  # Bypasses OS security model
options.add_argument("--disable-dev-shm-usage")  # Overcomes limited resource problems

service = Service(ChromeDriverManager().install())
driver = webdriver.Chrome(service=service, options=options)

urls = [
    ('https://market.csgo.com/en/Container/Operation%20Breakout%20Weapon%20Case', 'Operation Breakout Weapon Case'),
    ('https://market.csgo.com/en/Container/eSports%202013%20Winter%20Case', 'eSports 2013 Winter Case'),
    ('https://market.csgo.com/en/Container/Huntsman%20Weapon%20Case', ''),
    ('https://market.csgo.com/en/Container/Huntsman%20Weapon%20Case', 'Huntsman Weapon Case'),
    ('https://market.csgo.com/en/Container/CS:GO%20Weapon%20Case', 'CS:GO Weapon Case'),
    ('https://market.csgo.com/en/Container/eSports%202014%20Summer%20Case', 'eSports 2014 Summer Case'),
    ('https://market.csgo.com/en/Container/CS:GO%20Weapon%20Case%203', 'CS:GO Weapon Case 3'),
    ('https://market.csgo.com/en/Container/Operation%20Bravo%20Case', 'Operation Bravo Case'),
    ('https://market.csgo.com/en/Container/CS:GO%20Weapon%20Case%202', 'CS:GO Weapon Case 2'),
    ('https://market.csgo.com/en/Container/Winter%20Offensive%20Weapon%20Case', 'Winter Offensive Weapon Case'),
    ('https://market.csgo.com/en/Container/Operation%20Hydra%20Case', 'Operation Hydra Case'),
    ('https://market.csgo.com/en/Container/eSports%202013%20Case', 'eSports 2013 Case'),
    ('https://market.csgo.com/en/Container/Operation%20Vanguard%20Weapon%20Case', 'Operation Vanguard Weapon Case'),
    ('https://market.csgo.com/en/Container/Falchion%20Case', 'Falchion Case'),
    ('https://market.csgo.com/en/Container/Shattered%20Web%20Case', 'Shattered Web Case'),
    ('https://market.csgo.com/en/Container/Operation%20Wildfire%20Case', 'Operation Wildfire Case'),
    ('https://market.csgo.com/en/Container/Prisma%202%20Case', 'Prisma 2 Case'),
    ('https://market.csgo.com/en/Container/Operation%20Broken%20Fang%20Case', 'Operation Broken Fang Case'),
    ('https://market.csgo.com/en/Container/Horizon%20Case', 'Horizon Case'),
    ('https://market.csgo.com/en/Container/Chroma%20Case', 'Chroma Case'),
    ('https://market.csgo.com/en/Container/Gamma%202%20Case', 'Gamma 2 Case'),
    ('https://market.csgo.com/en/Container/Prisma%20Case', 'Prisma Case'),
    ('https://market.csgo.com/en/Container/Gamma%20Case', 'Gamma Case'),
    ('https://market.csgo.com/en/Container/Danger%20Zone%20Case', 'Danger Zone Case'),
    ('https://market.csgo.com/en/Container/Revolver%20Case', 'Revolver Case'),
    ('https://market.csgo.com/en/Container/Snakebite%20Case', 'Snakebite Case'),
    ('https://market.csgo.com/en/Container/Glove%20Case', 'Glove Case'),
    ('https://market.csgo.com/en/Container/Operation%20Riptide%20Case', 'Operation Riptide Case'),
    ('https://market.csgo.com/en/Container/Chroma%202%20Case', 'Chroma 2 Case'),
    ('https://market.csgo.com/en/Container/Recoil%20Case', 'Recoil Case'),
    ('https://market.csgo.com/en/Container/Spectrum%20Case', 'Spectrum Case'),
    ('https://market.csgo.com/en/Container/Shadow%20Case', 'Shadow Case'),
    ('https://market.csgo.com/en/Container/Dreams%20&%20Nightmares%20Case', 'Dreams & Nightmares Case'),
    ('https://market.csgo.com/en/Container/Clutch%20Case', 'Clutch Case'),
    ('https://market.csgo.com/en/Container/CS20%20Case', 'CS20 Case'),
    ('https://market.csgo.com/en/Container/Operation%20Phoenix%20Weapon%20Case', 'Operation Phoenix Weapon Case'),
    ('https://market.csgo.com/en/Container/Fracture%20Case', 'Fracture Case'),
    ('https://market.csgo.com/en/Container/Chroma%203%20Case', 'Chroma 3 Case'),
    ('https://market.csgo.com/en/Container/Spectrum%202%20Case', 'Spectrum 2 Case')
]

# Open the CSV file for writing
with open('data.csv', 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)

    for url, name in urls:
        driver.get(url)
        time.sleep(5)  # Wait for the page to load

        # Now use Selenium's methods to find elements
        WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'span.ng-star-inserted')))
        all_children = driver.find_elements(By.CSS_SELECTOR, 'span.ng-star-inserted')
        second_child_text = all_children[1].text if len(all_children) > 1 else "No data"
        
        # Get the name using the provided CSS selector from the HTML structure
        WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'span.mat-mdc-tooltip-trigger.mat-mdc-tooltip-disabled')))
        name_element = driver.find_element(By.CSS_SELECTOR, 'span.mat-mdc-tooltip-trigger.mat-mdc-tooltip-disabled')
        name_text = name_element.text

        # Write the data to the CSV file
        writer.writerow([name_text, second_child_text])


    result = insert_into_database(name_text, second_child_text, "market.csgo.com", "USD")  # Replace "CNY" with the actual currency if needed
    print(result)

driver.quit()