#include <iostream>
#include <string>
int main() {
	int n;
	std::cout << "Enter height: ";
	std::cin >> n;
    
	// Top
    std::cout << char(201);
    for (int i = 0; i <= 21; i++) {
    	std::cout << char(205);
	}
	std::cout << char(187) << std::endl;
	
	// Body
	std::string cute = " ";
	for (int i = 0; i <= 17; i++) {
		if (i == 8) {
			cute += "cute";
		} else {
			cute += " ";
		}
	}
	
	if (n % 2 == 0) {
		for (int i = 1; i <= n; i++) {
			if (i == n/2|| i == (n/2)+1) {
				std::cout << char(186) << cute << char(186) << std::endl;
			} else {
				std::cout << char(186) << "                      " << char(186) << std::endl;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (i == (n/2)+1) {
				std::cout << char(186) << cute << char(186) << std::endl;
			} else {
				std::cout << char(186) << "                      " << char(186) << std::endl;
			}
		}
	}
	
	// Bottom
	std::cout << char(200);
    for (int i = 0; i <= 21; i++) {
    	std::cout << char(205);
	}
	std::cout << char(188) << std::endl;
    return 0;
}