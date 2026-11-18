/*
    Project: Complex Number Calculator using C++ (Operator Overloading)
    Subject: Object Oriented Programming (C++)
    Standard: C++11 or later

    Features:
    - Complex class with real and imaginary parts
    - Default and parameterized constructor
    - Overloaded +, - and * operators
    - Friend function overloads << for readable output
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor creates 0 + 0i.
    // Parameterized constructor creates a + bi.
    Complex(double r = 0.0, double i = 0.0)
        : real(r), imag(i) {
    }

    // Addition of two complex numbers.
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction of two complex numbers.
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
// Multiplication of two complex numbers.
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Display a complex number in a + bi / a - bi format.
    friend std::ostream& operator<<(std::ostream& out, const Complex& value) {
        out << value.real
            << (value.imag < 0.0 ? " - " : " + ")
            << std::fabs(value.imag) << 'i';
        return out;
    }
};

// Read one finite numeric value. Reject text, infinities and NaN.
double readNumber(const std::string& prompt) {
    double value;

    while (true) {
        std::cout << prompt;

        if (std::cin >> value && std::isfinite(value)) {
            return value;
        }

        std::cout << "Invalid input. Please enter a valid finite number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    std::cout << "===== COMPLEX NUMBER CALCULATOR =====\n";
    std::cout << "Enter the real and imaginary parts of each number.\n\n";

    const double a = readNumber("First complex number - real part: ");
    const double b = readNumber("First complex number - imaginary part: ");
    const double c = readNumber("Second complex number - real part: ");
    const double d = readNumber("Second complex number - imaginary part: ");

    const Complex first(a, b);
    const Complex second(c, d);

    std::cout << "\n----- RESULTS -----\n";
    std::cout << "First       : " << first << '\n';
    std::cout << "Second      : " << second << '\n';
    std::cout << "Sum         : " << first + second << '\n';
    std::cout << "Difference  : " << first - second << '\n';
    std::cout << "Product     : " << first * second << '\n';

    return 0;
}
