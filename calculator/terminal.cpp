#include <string>
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

class Stack {
    int top;
    string arr[100]{};

public:
    Stack() { top = -1; }
    bool push(string x);
    string pop();
    bool isEmpty() const;
    string get_top();
};

bool Stack::push(string val) {
    if (top >= 99) {
        cout << "Stack is full";
        return false;
    } else {
        arr[++top] = val;
        return true;
    }
}

string Stack::pop() {
    if (top < 0) {
        cout << "Invalid expression";
        return 0;
    } else {
        string x = arr[top--];
        return x;
    }
}

bool Stack::isEmpty() const {
    return (top < 0);
}

string Stack::get_top() {
    return arr[top];
}

int precedence(string c) {
    if (c == "/" || c == "*")
        return 2;
    else if (c == "+" || c == "-")
        return 1;
    else
        return -1;
}

bool isOperator(string val) {
    return (val == "+" || val == "-" || val == "*" || val == "/" || val == "(" || val == ")");
}

vector<string> infixToPostfix (vector<string> infix) {
    Stack st;
    vector<string> postfix;

    for(auto &i : infix) {

        if (!isOperator(i)) {
            postfix.push_back(i);
        } else if (i == "(") {
            st.push("(");
        } else if (i == ")") {
            while(st.get_top() != "(") {
                postfix.push_back(st.get_top());
                st.pop();
            }
            st.pop();
        } else {
            while (!st.isEmpty() && precedence(i) <= precedence(st.get_top())) {
                postfix.push_back(st.get_top());
                st.pop();
            }
            st.push(i);
        }
    }

    while (!st.isEmpty()) {
        postfix.push_back(st.get_top());
        st.pop();
    }

    return postfix;
}

double evaluatePostfix(const vector<string>& postfix) {
    Stack st;

    for(auto& i : postfix) {

        if(!isOperator(i)) {
            st.push(i);
        } else {
            double operand2 = stod(st.pop());
            double operand1 = stod(st.pop());
            double result;

            if(i == "+") result = operand1 + operand2;
            else if(i == "-") result = operand1 - operand2;
            else if(i == "*") result = operand1 * operand2;
            else if(i == "/") result = operand1 / operand2;

            st.push(to_string(result));
        }
    }
    return stod(st.pop());
}

// MENU

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printMenu() {
    std::cout << char(201);
    for (int i = 0; i <= 35; i++) {
        std::cout << char(205);
    }
    std::cout << char(187) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 5; i++) {
        if (i == 2) {
            std::cout << "NAME: CATALLA, JOHANN SEBASTIAN";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(204);
    for (int i = 0; i <= 35; i++) {
        std::cout << char(205);
    }
    std::cout << char(185) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 2; i++) {
        if (i == 1) {
            std::cout << "STACK IMPLEMENTATION IN CALCULATOR";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(204);
    for (int i = 0; i <= 35; i++) {
        std::cout << char(205);
    }
    std::cout << char(185) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 23; i++) {
        if (i == 9) {
            std::cout << "1: CALCULATOR";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 17; i++) {
        if (i == 9) {
            std::cout << "2: INFIX TO POSTFIX";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 29; i++) {
        if (i == 9) {
            std::cout << "3: EXIT";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(204);
    for (int i = 0; i <= 35; i++) {
        std::cout << char(205);
    }
    std::cout << char(185) << std::endl;
    std::cout << char(186);
    for (int i = 0; i <= 28; i++) {
        if (i == 12) {
            std::cout << "CHOOSE: ";
        } else {
            std::cout << " ";
        }
    }
    std::cout << char(186) << std::endl;
    std::cout << char(200);
    for (int i = 0; i <= 35; i++) {
        std::cout << char(205);
    }
    std::cout << char(188) << std::endl;
}

int main() {
    string mainMenu = "y";
    int choice;
    while (mainMenu == "y") {
        printMenu();
        gotoxy(21, 9);
        cin >> choice;
        if (choice == 1) {
            system("cls");
            cout << "CALCULATOR: ";

            string s;

            cin >> s;

            vector<string> input;

            string temp = "";

            for (int i = 0; i < s.length(); i++) {

                if (!isOperator(s.substr(i,1)) && s[i] != '(' && s[i] != ')')
                    temp += s[i];

                else {
                    if (temp.length() > 0) {
                        input.push_back(temp);
                        temp = "";
                    }

                    input.push_back(s.substr(i,1));

                }

                if (i == s.length()-1 && !temp.empty())
                    input.push_back(temp);

            }
            vector<string> postfix = infixToPostfix(input);

            cout << "POSTFIX: | ";

            for(auto& i : postfix)
                cout << i << " | ";

            cout << endl;

            double res = evaluatePostfix(postfix);

            std::cout << "RESULT: " << res << endl;
        } else if (choice == 2) {
            system("cls");
            cout << "INFIX: ";

            string s;

            cin >> s;

            vector<string> input;

            string temp = "";

            for (int i = 0; i < s.length(); i++) {

                if (!isOperator(s.substr(i,1)) && s[i] != '(' && s[i] != ')')
                    temp += s[i];

                else {
                    if (temp.length() > 0) {
                        input.push_back(temp);
                        temp = "";
                    }

                    input.push_back(s.substr(i,1));

                }

                if (i == s.length()-1 && !temp.empty())
                    input.push_back(temp);

            }

            vector<string> postfix = infixToPostfix(input);

            cout << "POSTFIX: | ";

            for(auto& i : postfix)
                cout << i << " | ";

            cout << endl;
        } else {
            break;
        }

        std::cout << "\nGo back to main menu? [y/n]: ";
        std::cin >> mainMenu;
        std::cout << std::endl;
        if (mainMenu != "y") {
            break;
        } else {
            system("cls");
        }
    }

    return 0;
}
