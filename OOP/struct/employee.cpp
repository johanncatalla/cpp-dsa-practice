#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

struct Employee {
    std::string name;
    std::string ID;
    std::string position;
    float salary;
    float hrs_worked;
};

void addEmployee(std::unordered_map<std::string, Employee> &employees) {
    Employee person;
    std::cout << "Enter employee name: ";
    std::getline(std::cin, person.name);
    std::cout << "Enter employee ID: ";
    std::getline(std::cin, person.ID);
    std::cout << "Enter employee position: ";
    std::getline(std::cin, person.position);
    std::cout << "Enter employee salary: ";
    std::cin >> person.salary;
    std::cout << "Enter employee hours worked: ";
    std::cin >> person.hrs_worked;

    // store person struct as value and id as key for easy access
    employees[person.ID] = person;
    std::cout << "\nEmployee added\n\n";
}

void deleteEmployee(std::unordered_map<std::string, Employee> &employees, const std::string &ID) {
    auto it = employees.find(ID);
    employees.erase(it);
}

void searchEmployee(std::unordered_map<std::string, Employee> &employees, const std::string& ID) {
    auto it = employees.find(ID);
    if (it != employees.end()) {
        const Employee &employee = it->second;
        std::cout << "\nEmployee details: " << std::endl;
        std::cout << "Name: " << employee.name << std::endl;
        std::cout << "ID: " << employee.ID << std::endl;
        std::cout << "Position: " << employee.position << std::endl;
        printf("Salary: $%.2f\n", employee.salary);
        std::cout << "Hours worked: " << employee.hrs_worked << std::endl;
        std::cout << std::endl;
    } else {
        std::cout << "Employee not found";
    }
}

void displayPayroll(std::unordered_map<std::string, Employee> &employees) {
    float totalPayroll = 0;
    for (auto it = employees.begin(); it != employees.end(); it++) {
        const Employee &employee = it->second;
        totalPayroll += employee.salary * employee.hrs_worked;
    }

    printf("Total payroll: $%.2f\n\n", totalPayroll);
}

int main() {
    std::unordered_map<std::string, Employee> employees;
    std::unordered_map<int, std::function<void(std::unordered_map<std::string, Employee>&)>> choices = {
        {1, [](std::unordered_map<std::string, Employee> &employees) { addEmployee(employees); }},
        {2, [](std::unordered_map<std::string, Employee> &employees) {
            std::string ID;
            std::cout << "Enter employee ID to delete: ";
            std::cin >> ID;
            deleteEmployee(employees, ID);
            std::cout << "\nEmployee deleted\n\n"; }},
        {3, [](std::unordered_map<std::string, Employee> &employees) {
            std::string ID;
            std::cout << "Enter employee ID to search: ";
            std::getline(std::cin, ID);
            searchEmployee(employees, ID);}},
        {4, [](std::unordered_map<std::string, Employee> &employees) { displayPayroll(employees); }}
    };
    int choice = 0;

    while (choice != 5) {
        std::cout << "1. Add employee"
                  << "\n2. Delete employee"
                  << "\n3. Search employee"
                  << "\n4. Display total payroll"
                  << "\n5. Exit" << std::endl;

        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << "\n";
        std::cin.ignore();

        if (choices.find(choice) != choices.end()) {
            choices[choice](employees);
        }
        
    }
    return 0;
}
