#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdexcept>

class Tokenizer {
private:
    std::string expression;
    int index = 0;

public:
    Tokenizer(const std::string& expr) : expression(expr) {
        // Trim the expression
        size_t first = expression.find_first_not_of(' ');
        size_t last = expression.find_last_not_of(' ');
        expression = expression.substr(first, (last - first + 1));
    }

    std::vector<std::string> tokenize() {
        std::vector<std::string> tokens;
        std::string number;
        int openBrackets = 0;
        int closeBrackets = 0;

        while (index < expression.length()) {
            char c = expression[index];
            if (isdigit(c) || c == '.') {
                number += c;
            } else {
                if (!number.empty()) {
                    tokens.push_back(number);
                    number.clear();
                }
                if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
                    tokens.push_back(std::string(1, c));
                    if (c == '(') openBrackets++;
                    if (c == ')') closeBrackets++;
                } else if (!isspace(c)) {
                    throw std::runtime_error("Illegal token found: " + std::string(1, c));
                }
            }
            index++;
        }
        if (!number.empty()) {
            tokens.push_back(number);
        }
        if (openBrackets != closeBrackets) {
            throw std::runtime_error("Mismatched brackets found in the expression.");
        }
        return tokens;
    }
};

class Read {
public:
    static std::string input() {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }
};

class Evaluator {
public:
    double evaluate(const std::vector<std::string>& tokens) {
        std::stack<double> numbers;
        std::stack<char> operators;

        for (const std::string& token : tokens) {
            if (token == "(") {
                operators.push(token[0]);
            } else if (token == ")") {
                while (operators.top() != '(') {
                    double b = numbers.top(); numbers.pop();
                    double a = numbers.top(); numbers.pop();
                    numbers.push(applyOperation(operators.top(), a, b));
                    operators.pop();
                }
                operators.pop();  // Remove the opening bracket
            } else if (isOperator(token)) {
                char op = token[0];
                while (!operators.empty() && hasPrecedence(op, operators.top())) {
                    double b = numbers.top(); numbers.pop();
                    double a = numbers.top(); numbers.pop();
                    numbers.push(applyOperation(operators.top(), a, b));
                    operators.pop();
                }
                operators.push(op);
            } else {
                numbers.push(std::stod(token));
            }
        }

        while (!operators.empty()) {
            double b = numbers.top(); numbers.pop();
            double a = numbers.top(); numbers.pop();
            numbers.push(applyOperation(operators.top(), a, b));
            operators.pop();
        }
        return numbers.top();
    }

private:
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    bool hasPrecedence(char op1, char op2) {
        if (op2 == '(' || op2 == ')') {
            return false;
        }
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
            return false;
        }
        return true;
    }

    double applyOperation(char op, double a, double b) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b == 0.0) {
                    throw std::runtime_error("Cannot divide by zero.");
                }
                return a / b;
            default:
                throw std::runtime_error("Unknown operator.");
        }
    }
};

int main() {
    std::cout << "Enter the arithmetic expression: ";
    std::string expression = Read::input();

    try {
        Tokenizer tokenizer(expression);
        Evaluator evaluator;

        std::vector<std::string> tokens = tokenizer.tokenize();
        double result = evaluator.evaluate(tokens);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
