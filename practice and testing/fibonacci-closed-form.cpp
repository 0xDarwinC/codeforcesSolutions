#include <iostream>
#include <chrono>
#include <cmath>

constexpr double sqrt5 = 2.23606797749979;
constexpr double phi = (1.0 + sqrt5) / 2.0;
constexpr double psi = (1.0 - sqrt5) / 2.0;

constexpr int fibonacci(int n) {
    return static_cast<int>((std::pow(phi, n) - std::pow(psi, n)) / sqrt5 + 0.5);
}

// Regular recursive Fibonacci (inefficient for large n)
int fib_recursive(int n) {
    return (n <= 1) ? n : fib_recursive(n - 1) + fib_recursive(n - 2);
}





int main() {
    const int ten = 10;
    constexpr int fib10 = fibonacci(ten); // Should be 55
    static_assert(fib10 == 55, "Incorrect Fibonacci calculation");
    return 0;
}


int main() {
    int x = 30; // Runtime variable

    auto start1 = std::chrono::high_resolution_clock::now();
    int result1 = fibonacci(x); // Using constexpr function
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    int result2 = fib_recursive(x); // Using regular recursive function
    auto end2 = std::chrono::high_resolution_clock::now();

    std::cout << "Fibonacci constexpr: " << result1 << " | Time: "
              << std::chrono::duration<double, std::micro>(end1 - start1).count() << " us\n";

    std::cout << "Fibonacci recursive: " << result2 << " | Time: "
              << std::chrono::duration<double, std::micro>(end2 - start2).count() << " us\n";

    return 0;
}