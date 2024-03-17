#include <iostream>
#include <string>

int main() {
    std::string firstSevenDigits = "1234567"; // replace with your first seven digits
    std::string correctNumber = "1234567766";

    for (int i = 0; i <= 999; ++i) {
        std::string lastThreeDigits = std::to_string(i);

        // Pad with leading zeros if necessary
        while (lastThreeDigits.length() < 3) {
            lastThreeDigits = "0" + lastThreeDigits;
        }

        std::string fullNumber = firstSevenDigits + lastThreeDigits;

        if (fullNumber == correctNumber) {
            std::cout << "Number Found: " << fullNumber << std::endl;
        }
    }
    return 0;
}
