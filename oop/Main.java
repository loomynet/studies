public class Main {

    public static class BankAccount {
        private int accountNumber;
        private int accountBalance;
        private String ownerName;

        public BankAccount(int accountNumber, int accountBalance, String ownerName) {
            this.accountNumber = accountNumber;
            this.accountBalance = accountBalance > 0 ? accountBalance : 0;
            this.ownerName = ownerName;
        }

        public void deposit(int amount) {
            if (amount > 0) {
                accountBalance += amount;
            } else {
                System.out.println("Deposit amount must be positive.");
            }
        }

        public void withdraw(int amount) {
            if (amount > 0 && amount <= accountBalance) {
                accountBalance -= amount;
            } else if (amount > accountBalance) {
                System.out.println("Insufficient balance for withdrawal.");
            } else {
                System.out.println("Withdrawal amount must be positive.");
            }
        }

        public void addInterest(double interestRate) {
            if (interestRate > 0) {
                accountBalance += (int) (accountBalance * (interestRate / 100));
            } else {
                System.out.println("Interest rate must be positive.");
            }
        }

        public void printAccountDetails() {
            System.out.println("Account Number: " + accountNumber);
            System.out.println("Owner Name: " + ownerName);
            System.out.println("Account Balance: $" + accountBalance);
        }

        public int getAccountNumber() {
            return accountNumber;
        }

        public int getAccountBalance() {
            return accountBalance;
        }

        public String getOwnerName() {
            return ownerName;
        }
    }

    public static void main(String[] args) {
        
        BankAccount bankAccount = new BankAccount(1, 100, "Andrejs");

        bankAccount.deposit(100);
        bankAccount.withdraw(20);
        bankAccount.withdraw(500);
        bankAccount.addInterest(5);
        bankAccount.printAccountDetails();
    }
}
