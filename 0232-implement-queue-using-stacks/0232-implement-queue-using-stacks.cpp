#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        // Constructor
    }
    
    void push(int x) {
        // Push element onto the input stack
        inputStack.push(x);
    }
    
    int pop() {
        // Ensure the output stack has the elements in the correct order
        moveToOutputStack();
        int frontElement = outputStack.top(); // Get the front element
        outputStack.pop(); // Remove it from the output stack
        return frontElement;
    }
    
    int peek() {
        // Ensure the output stack has the elements in the correct order
        moveToOutputStack();
        return outputStack.top(); // Return the front element without removing it
    }
    
    bool empty() {
        // Return true if both stacks are empty
        return inputStack.empty() && outputStack.empty();
    }

private:
    stack<int> inputStack;   // Stack to handle incoming elements
    stack<int> outputStack;  // Stack to handle outgoing elements

    // Move elements from inputStack to outputStack if outputStack is empty
    void moveToOutputStack() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
