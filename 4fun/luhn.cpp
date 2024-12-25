#include <iostream>

std::string getCardNumber() {
  std::string cardNumber;
  std::cout << "Hello, this is a Luhn algorithm card number validator, please, "
               "enter the card number without spaces to check if it's valid:"
            << "\n";
  while (true) {
    std::cin >> cardNumber;
    bool valid = true;

    if (cardNumber.length() == 16) {
      for (int i = 0; i < 16; i++) {
        if (!(cardNumber[i] >= '0' && cardNumber[i] <= '9')) {
          valid = false;
          break;
        }
      }
    } else {
      valid = false;
    }

    if (valid) {
      return cardNumber;
    } else {
      std::cout << "Not a valid card number, the length must be 16 digits and "
                   "must not contain any spaces, letters or special "
                   "characters. Please try again:"
                << "\n";
    }
  }
}

void cardNumberValidation(std::string cardNumber) {
  int total = 0;
  int temp = 0;
  for (int i = 14; i >= 0; i -= 2) {
    temp = (cardNumber[i] - '0') * 2;
    if (temp > 9) {
      temp -= 9;
      total += temp;
    } else {
      total += temp;
    }
  }

  for (int i = 15; i >= 0; i -= 2) {
    total += (cardNumber[i] - '0');
  }

  if (total % 10 == 0) {
    std::cout << "This card number is valid!" << "\n";
  } else {
    std::cout << "This card number is not valid!" << "\n";
  }
}

int main() {
  std::string cardNumber = getCardNumber();
  cardNumberValidation(cardNumber);
  return 0;
}
