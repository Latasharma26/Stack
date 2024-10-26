#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {
        // Constructor
    }
    
    void push(int x) {
        // Push the new element onto queue2
        queue2.push(x);
        
        // Push all elements from queue1 to queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        
        // Swap the names of the queues
        swap(queue1, queue2);
    }
    
    int pop() {
        int topElement = queue1.front(); // Get the front element (top of the stack)
        queue1.pop(); // Remove it from the queue
        return topElement;
    }
    
    int top() {
        return queue1.front(); // Return the front element without removing it
    }
    
    bool empty() {
        return queue1.empty(); // Return true if the queue is empty
    }

private:
    queue<int> queue1; // Main queue
    queue<int> queue2; // Temporary queue
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
