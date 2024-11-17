#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cctype>
#include <sstream>

using namespace std;

string trim(const string& str) {
    size_t first = str.find_first_not_of(" 	\n\r");
    if (first == string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" 	\n\r");
    return str.substr(first, (last - first + 1));
}

bool is_numeric(const string& str) {
    string trimmed_str = trim(str);
    return !trimmed_str.empty() && all_of(trimmed_str.begin(), trimmed_str.end(), ::isdigit);
}

vector<int> read_data(const string& file_path) {
    vector<int> data;
    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << file_path << endl;
        return data;
    }

    string line;
    while (getline(file, line)) {
        line = trim(line);
        if (is_numeric(line)) {
            try {
                data.push_back(stoi(line));
            } catch (const invalid_argument& e) {
                cerr << "Warning: Invalid numeric data found and ignored: " << line << endl;
            } catch (const out_of_range& e) {
                cerr << "Warning: Numeric value out of range and ignored: " << line << endl;
            }
        }
    }

    if (data.empty()) {
        cerr << "Warning: No valid numeric data found in file " << file_path << endl;
    }

    return data;
}

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void benchmark_sorting_algorithms(const vector<int>& data) {
    if (data.empty()) {
        cerr << "Error: No data to sort." << endl;
        return;
    }

    vector<int> data_copy;

    data_copy = data;
    auto start = chrono::high_resolution_clock::now();
    selection_sort(data_copy);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Selection Sort: " << elapsed.count() << " seconds" << endl;
    ofstream output_file("selection_sorted_data.txt");
    if (output_file.is_open()) {
        for (const auto& item : data_copy) {
            output_file << item << "\n";
        }
        output_file.close();
    } else {
        cerr << "Error: Could not write to selection_sorted_data.txt" << endl;
    }

    data_copy = data;
    start = chrono::high_resolution_clock::now();
    merge_sort(data_copy, 0, data_copy.size() - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Merge Sort: " << elapsed.count() << " seconds" << endl;
    output_file.open("merge_sorted_data.txt");
    if (output_file.is_open()) {
        for (const auto& item : data_copy) {
            output_file << item << "\n";
        }
        output_file.close();
    } else {
        cerr << "Error: Could not write to merge_sorted_data.txt" << endl;
    }

    data_copy = data;
    start = chrono::high_resolution_clock::now();
    quick_sort(data_copy, 0, data_copy.size() - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Quick Sort: " << elapsed.count() << " seconds" << endl;
    output_file.open("quick_sorted_data.txt");
    if (output_file.is_open()) {
        for (const auto& item : data_copy) {
            output_file << item << "\n";
        }
        output_file.close();
    } else {
        cerr << "Error: Could not write to quick_sorted_data.txt" << endl;
    }
}

int main() {
    vector<int> data = read_data("athlets.data");
    benchmark_sorting_algorithms(data);
    return 0;
}