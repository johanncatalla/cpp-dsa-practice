#include <iostream>
#include <string>

void square(int num);

void square(int num) {
	std::cout << num * num << std::endl;
}


int main() {
	std::string pass;
	short num = 1;
	
	do {
		std::cout << "Enter password: ";
		std::cin >> pass;
	} while (pass != "SECRET");
	
	if (pass=="SECRET") {
		
		std::cout << "FOR LOOP" << std::endl;
		for (int i = 1; i<=10; i++) {
			square(i);
		}
		
		std::cout << "\nWHILE LOOP" << std::endl;
		while (num <= 10) {
			square(num);
			num++;
		}		
}
}
