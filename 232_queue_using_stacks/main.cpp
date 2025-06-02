/**************************************************************************************
 * Problem 232: Implenet Queue using Stacks: Easy
 * 
 * Implement a first in first out (FIFO) queue using only two stacks. 
 * The implemented queue should support all the functions of a normal queue 
 * (push, peek, pop, and empty).
 * 
 * Implement the MyQueue class:
 *      1. void push(int x) Pushes element x to the back of the queue.
 *      2. int pop() Removes the element from the front of the queue and returns it.
 *      3. int peek() Returns the element at the front of the queue.
 *      4. boolean empty() Returns true if the queue is empty, false otherwise.
 * 
 * You must use only standard operations of a stack, which means only 
 * push to top, peek/pop from top, size, and is empty operations are valid.
 * 
**************************************************************************************/

#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> stack_in;
    std::stack<int> stack_out;

    // Helper to transfer elements from stack_in to stack_out
    void transferInToOut() {
        while (!stack_in.empty()) {
            stack_out.push(stack_in.top());
            stack_in.pop();
        }
    }

public:
    MyQueue() {}
        
    void push(int x) {
        stack_in.push(x);
    }
        
    int pop() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        
        int temp = stack_out.top();
        stack_out.pop();
        return temp;
    }
        
    int peek() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        return stack_out.top();
    }
        
    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }

    void printState() {
        std::stack<int> temp_out = stack_out;
        std::stack<int> temp_in = stack_in;
        std::stack<int> simulated;

        // Transfer stack_in to simulate the full queue state
        while (!temp_in.empty()) {
            simulated.push(temp_in.top());
            temp_in.pop();
        }

        // Push existing stack_out contents to the output first
        std::cout << "Queue state (front to back): ";
        while (!temp_out.empty()) {
            std::cout << temp_out.top() << " ";
            temp_out.pop();
        }

        // Then push transferred elements
        while (!simulated.empty()) {
            std::cout << simulated.top() << " ";
            simulated.pop();
        }

        std::cout << std::endl;
    }
};

int main() {
    MyQueue q;

    q.printState();  // Should be empty

    q.push(10);
    q.push(20);
    q.push(30);

    q.printState();  // Expected: 10 20 30

    std::cout << "Pop: " << q.pop() << std::endl;  // 10
    q.printState();  // Expected: 20 30

    std::cout << "Peek: " << q.peek() << std::endl;  // 20
    q.printState();  // Still: 20 30

    q.pop();
    q.pop();
    q.printState();  // Should be empty again

    std::cout << "Empty? " << (q.empty() ? "Yes" : "No") << std::endl;

    return 0;
}