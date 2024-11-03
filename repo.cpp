#include <iostream>
#include <stack>
#include <tuple>

int ackermann_non_recursive(int m, int n) {
    std::stack<std::tuple<int, int>> stack;
    stack.push(std::make_tuple(m, n));

    while (!stack.empty()) {
        std::tie(m, n) = stack.top();
        stack.pop();

        if (m == 0) {
            return n + 1;
        }
        else if (m == 1) {
            return n + 2;
        }
        else if (m == 2) {
            return 2 * n + 3;
        }
        else if (m == 3) {
            return (1 << (n + 3)) - 3;
        }
        else {
            stack.push(std::make_tuple(m - 1, -1)); 
            stack.push(std::make_tuple(m, n - 1)); 
            n = -1;
        }

        if (n == -1 && !stack.empty()) {
            n = std::get<1>(stack.top());
            stack.pop();
            stack.push(std::make_tuple(m - 1, n));
        }
    }
    return n;
}

int main() {
    std::cout << "Ackermann(3, 4) = " << ackermann_non_recursive(3, 4) << std::endl; 
    return 0;
}