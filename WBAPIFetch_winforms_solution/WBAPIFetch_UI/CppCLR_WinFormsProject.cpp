#include "include/exception"
#include "include/future"
#include "pch.h"
#include "Form1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <thread>
#include <future>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <limits>
#include <cstdio>

#ifdef max
#undef max
#endif

#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;

const std::unordered_map<std::string, std::string> INDICATORS =
{
    {"GDP Growth", "NY.GDP.MKTP.KD.ZG"},
    {"Unemployment", "SL.UEM.TOTL.ZS"},
    {"Inflation (CPI)", "FP.CPI.TOTL.ZG"},
    {"Gov Debt", "GC.DOD.TOTL.GD.ZS"},
    {"Current Account Balance", "BN.CAB.XOKA.GD.ZS"},
    {"FDI Net Inflows", "BX.KLT.DINV.CD.WD"},
    {"PPP Conversion Factor", "PA.NUS.PPP"}
};

const std::unordered_map<std::string, std::string> INDICATOR_DESCRIPTIONS =
{
    {"GDP Growth", "Gross Domestic Product Growth Rate"},
    {"Unemployment", "Unemployment Rate"},
    {"Inflation (CPI)", "Consumer Price Index Inflation Rate"},
    {"Gov Debt", "Government Debt to GDP Ratio"},
    {"Current Account Balance", "Current Account Balance as a percentage of GDP"},
    {"FDI Net Inflows", "Foreign Direct Investment Net Inflows"},
    {"PPP Conversion Factor", "Purchasing Power Parity Conversion Factor"}
};

const std::string BASE_URL = "http://api.worldbank.org/v2/country";
std::string CSV_FILENAME = "world_bank_data.csv";

int START_YEAR = 2000;
int END_YEAR = 2021;
std::vector<std::string> SELECTED_COUNTRIES;
std::vector<std::string> SELECTED_INDICATORS;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s)
{
    size_t newLength = size * nmemb;
    try 
    {
        s->append((char*)contents, newLength);
    }

    catch (std::bad_alloc& e) 
    {
        return 0;
    }

    return newLength;
}

nlohmann::json fetch_data(const std::string& country_code, const std::string& indicator_code)
{
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    std::string url = BASE_URL + "/" + country_code + "/indicator/" + indicator_code + "?format=json&date=" + std::to_string(START_YEAR) + ":" + std::to_string(END_YEAR);

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK)
        {
            std::cerr << "Failed to fetch data for " << country_code << " and " << indicator_code << ". Error: " << curl_easy_strerror(res) << std::endl;
            return nlohmann::json(); // Return an empty JSON object
        }
    }

    return nlohmann::json::parse(readBuffer);
}

std::string json_to_string(const nlohmann::json& value)
{
    if (value.is_null())
    {
        return "";
    }
    else if (value.is_string())
    {
        return value.get<std::string>();
    }
    else if (value.is_number_integer())
    {
        return std::to_string(value.get<int>());
    }
    else if (value.is_number_float())
    {
        return std::to_string(value.get<double>());
    }
    else
    {
        return value.dump();
    }
}

void write_to_csv(const std::string& country_code, const std::string& indicator_name, const nlohmann::json& data)
{
    std::ofstream csvfile(CSV_FILENAME, std::ios::app);
    for (const auto& entry : data[1])
    {
        std::string year = entry["date"].get<std::string>();
        std::string value = json_to_string(entry["value"]);
        csvfile << country_code << "," << indicator_name << "," << year << "," << value << "\n";
    }

    std::cout << "Data for " << country_code << " - " << indicator_name << " written to " << CSV_FILENAME << std::endl;
}

void fetch_and_save_data()
{
    try
    {
        if (std::remove(CSV_FILENAME.c_str()) != 0)
        {
            std::perror("Error deleting old CSV file");
        }
        else
        {
            std::cout << "Old CSV file successfully deleted.\n";
        }

        std::ofstream csvfile(CSV_FILENAME);
        csvfile << "Country Code,Indicator,Year,Value\n";
        csvfile.close();

        std::vector<std::future<nlohmann::json>> futures;

        for (const auto& country_code : SELECTED_COUNTRIES)
        {
            for (const auto& indicator : SELECTED_INDICATORS)
            {
                try
                {
                    if (INDICATORS.find(indicator) != INDICATORS.end())
                    {
                        futures.push_back(std::async(std::launch::async, fetch_data, country_code, INDICATORS.at(indicator)));
                    }
                    else
                    {
                        std::cerr << "Indicator not found: " << indicator << std::endl;
                    }
                }

                catch (const std::exception& ex)
                {
                    std::cerr << "Error fetching data for " << country_code << " and " << indicator << ": " << ex.what() << std::endl;
                }
            }
        }

        for (size_t i = 0; i < futures.size(); ++i)
        {
            try
            {
                auto result = futures[i].get();
                if (!result.is_null())
                {
                    if (result.size() > 1 && !result[1].empty())
                    {
                        std::string country_code = result[1][0]["countryiso3code"].get<std::string>();
                        std::string indicator_name = result[1][0]["indicator"]["value"].get<std::string>();
                        write_to_csv(country_code, indicator_name, result);
                    }
                    else
                    {
                        std::cerr << "Result data structure is not as expected or is empty." << std::endl;
                    }
                }
                else
                {
                    std::cerr << "No result received from the API." << std::endl;
                }
            }

            catch (const std::exception& ex)
            {
                std::cerr << "Error processing future result: " << ex.what() << std::endl;
            }
        }

        std::cout << "Data fetching and saving complete." << std::endl;
    }

    catch (const std::exception& ex)
    {
        std::cerr << "Exception in fetch_and_save_data: " << ex.what() << std::endl;
    }
}

#pragma managed

void CppCLRWinFormsProject::Form1::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        SELECTED_COUNTRIES.clear();
        SELECTED_INDICATORS.clear();

        for (int i = 0; i < checkedListBox1->CheckedItems->Count; i++)
        {
            std::string country_code = msclr::interop::marshal_as<std::string>(checkedListBox1->CheckedItems[i]->ToString());
            SELECTED_COUNTRIES.push_back(country_code);
        }

        for (int i = 0; i < checkedListBox2->CheckedItems->Count; i++)
        {
            std::string indicator_name = msclr::interop::marshal_as<std::string>(checkedListBox2->CheckedItems[i]->ToString());
            SELECTED_INDICATORS.push_back(indicator_name);
        }

        std::string years_range = msclr::interop::marshal_as<std::string>(textBox1->Text);
        std::string start_year, end_year;
        std::istringstream iss(years_range);

        if (std::getline(iss, start_year, '-') && std::getline(iss, end_year))
        {
            START_YEAR = std::stoi(start_year);
            END_YEAR = std::stoi(end_year);
        }

        CSV_FILENAME = msclr::interop::marshal_as<std::string>(textBox2->Text) + "\\world_bank_data.csv";

        std::cout << "Starting data fetch and save task..." << std::endl;

        Task::Run(gcnew Action(fetch_and_save_data));
    }

    catch (const std::exception& ex)
    {
        std::cerr << "Exception in button2_Click: " << ex.what() << std::endl;
    }
}

void CppCLRWinFormsProject::Form1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("GDP Growth: Gross Domestic Product Growth Rate \nUnemployment: Unemployment rate \nInflation (CPI): Consumer Price Index Inflation Rate \nGov Debt: Government Debt to GDP Ratio \nCurrent Account Balance: Current Account Balance as a percentage of GDP \nFDI Net Inflows: Foreign Direct Investment Net Inflows \nPPP Conversion Factor: Purchasing Power Parity Conversion Factor \nMore info: https://data.worldbank.org/indicator", "Indicators", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

void CppCLRWinFormsProject::Form1::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        textBox2->Text = folderBrowserDialog1->SelectedPath;
    }
}

[STAThread]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CppCLRWinFormsProject::Form1 form;
    Application::Run(% form);
}