#include <iostream>
using namespace std;

int main() {
    float num1, num2, result;
    char op;

    cout << "Simple Calculator" << endl;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    if (op == '+') {
        result = num1 + num2;
        cout << "Result = " << result << endl;
    }
    else if (op == '-') {
        result = num1 - num2;
        cout << "Result = " << result << endl;
    }
    else if (op == '*') {
        result = num1 * num2;
        cout << "Result = " << result << endl;
    }
    else if (op == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            cout << "Result = " << result << endl;
        } else {
            cout << "Error: divide by zero" << endl;
        }
    }
    else {
        cout << "Invalid operator" << endl;
    }

    return 0;
}
