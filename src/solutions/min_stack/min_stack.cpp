/*
 * Min Stack
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *   - push(x)  -- Push element x onto stack.
 *   - pop()    -- Removes the element on top of the stack.
 *   - top()    -- Get the top element.
 *   - getMin() -- Retrieve the minimum element in the stack.
 *
 * Tags: Stack, Data Structure
 */

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;
public:
    void push(int x) {
        stk.push(x);
        if (min_stk.empty() || x <= min_stk.top())
            min_stk.push(x);
    }

    void pop() {
        int x = stk.top();
        stk.pop();
        if (x == min_stk.top())
            min_stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
};

int main(int argc, char **argv) {
    MinStack stk;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string operation;
        iss >> operation;
        if (operation == "push") {
            int value;
            iss >> value;
            stk.push(value);
        } else if (operation == "pop") {
            stk.pop();
        } else if (operation == "top") {
            cout << stk.top() << endl;
        } else if (operation == "min") {
            cout << stk.getMin() << endl;
        }
    }
    return 0;
}
