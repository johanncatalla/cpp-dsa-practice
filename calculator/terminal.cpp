#include <string>
#include <vector>
#include <iostream>

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

bool Stack::push(string x) {
    if (top >= 99) {
        cout << "Stack is full";
        return false;
    } else {
        arr[++top] = x;
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

bool isOperator(string c) {
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "(" || c == ")");
}

vector<string> infixToPostfix (vector<string> s) {
    Stack st;
    vector<string> postfix;

    for(auto &i : s) {

        if (!isOperator(i))
            postfix.push_back(i);

        else if (i == "(")
            st.push("(");

        else if (i == ")") {
            while(st.get_top() != "(") {
                postfix.push_back(st.get_top());
                st.pop();
            }
            st.pop();
        }

        else {
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

        if(!isOperator(i))
            st.push(i);

        else {
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

int main() {

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

    std::cout << "RESULT: " << res;

    string exit;
    std::cout << "\n\nExit? [y/n]: ";
    std::cin >> exit;
    return 0;
}
