<?php

declare(strict_types = 1);

$root = dirname(__DIR__) . DIRECTORY_SEPARATOR;

define('APP_PATH', $root . 'app' . DIRECTORY_SEPARATOR);
define('FILES_PATH', $root . 'transaction_files' . DIRECTORY_SEPARATOR);
define('VIEWS_PATH', $root . 'views' . DIRECTORY_SEPARATOR);

/* YOUR CODE (Instructions in README.md) */


// Directory containing transaction files

$dir = __DIR__ . '/../transaction_files';

// Function to parse a single CSV file
function parseCSV($filePath)
{
    $rows = [];
    if (($handle = fopen($filePath, 'r')) !== FALSE) {
        // Skip the header
        $header = fgetcsv($handle);

        // Read rows
        while (($data = fgetcsv($handle)) !== FALSE) {
            $rows[] = $data;
        }
        fclose($handle);
    }
    return $rows;
}

// Function to process all CSV files
function processTransactionFiles($dir)
{
    $allTransactions = [];

    // Scan directory for CSV files
    foreach (scandir($dir) as $file) {
        $filePath = "$dir/$file";
        if (is_file($filePath) && pathinfo($filePath, PATHINFO_EXTENSION) === 'csv') {
            // Parse CSV file and merge its rows with other transactions
            $transactions = parseCSV($filePath);
            $allTransactions = array_merge($allTransactions, $transactions);
        }
    }

    return $allTransactions;
}

// Function to display transactions as an HTML table
function generateHTMLTable($transactions)
{
    $totalIncome = 0;
    $totalExpense = 0;

    echo "<table>";
    echo "<tr><th>Date</th><th>Check #</th><th>Description</th><th>Amount</th></tr>";

    foreach ($transactions as $transaction) {
        $date = $transaction[0];
        $checkNum = $transaction[1] ?: 'N/A';  // Handle null check numbers
        $description = $transaction[2];
        $amount = str_replace(['$', ','], '', $transaction[3]);

        // Calculate totals
        if ($amount < 0) {
            $totalExpense += $amount;
            $amount = "<span style='color:red;'>$$amount</span>";
        } else {
            $totalIncome += $amount;
            $amount = "<span style='color:green;'>$$amount</span>";
        }

        // Display row
        echo "<tr><td>$date</td><td>$checkNum</td><td>$description</td><td>$amount</td></tr>";
    }

    echo "</table>";

    // Display totals
    echo "<p>Total Income: $" . number_format($totalIncome, 2) . "</p>";
    echo "<p>Total Expense: $" . number_format($totalExpense, 2) . "</p>";
    echo "<p>Net Total: $" . number_format($totalIncome + $totalExpense, 2) . "</p>";
}

// Get all transactions from CSV files
$transactions = processTransactionFiles($dir);

// Generate the HTML table
generateHTMLTable($transactions);


