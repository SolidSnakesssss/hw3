#include <iostream>
#include "stack.h" // Include your Stack header file here

int main() {
    // Create a stack of integers
    Stack<int> stack;

    // Push some elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(50);
    stack.push(20);
    stack.push(10);

    // Print the size of the stack
    std::cout << "Size of stack: " << stack.size() << std::endl;

    // Check if the stack is empty
    if (!stack.empty()) {
        // Print the top element of the stack
        std::cout << "Top element of stack: " << stack.top() << std::endl;
    }

    // Pop elements from the stack
    while (!stack.empty()) {
        std::cout << "Popping: " << stack.top() << std::endl;
        stack.pop();
    }

    // Check if the stack is empty after popping
    if (stack.empty()) {
        std::cout << "Stack is empty" << std::endl;
    }

    return 0;
}