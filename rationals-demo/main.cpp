#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::string;

class Rational 
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

public:
    Rational(int num, int den) : numerator(num), denominator(den) 
    {
        if (denominator == 0) 
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
    }

    Rational simplify() 
    {
        int gcd_val = gcd(numerator, denominator);
        return Rational(numerator / gcd_val, denominator / gcd_val);
    }

    Rational operator+(const Rational& other) 
    {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator).simplify();
    }

    Rational operator-(const Rational& other) 
    {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator).simplify();
    }

    Rational operator*(const Rational& other) 
    {
        return Rational(numerator * other.numerator, denominator * other.denominator).simplify();
    }

    Rational operator/(const Rational& other) 
    {
        return Rational(numerator * other.denominator, denominator * other.numerator).simplify();
    }

    string toString() 
    {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};

int main() {
    try 
    {
        Rational a(35, 274);
        Rational b(29, 46);

        cout << a.toString() << " + " << b.toString() << " = " << (a + b).toString() << "\n";
        cout << a.toString() << " - " << b.toString() << " = " << (a - b).toString() << "\n";
        cout << a.toString() << " * " << b.toString() << " = " << (a * b).toString() << "\n";
        cout << a.toString() << " / " << b.toString() << " = " << (a / b).toString() << "\n";
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}
