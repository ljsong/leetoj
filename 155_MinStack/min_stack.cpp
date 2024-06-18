#include <vector>
#include <set>
#include <map>
#include <iostream>

class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        data.push_back(val);
        ++min_stack[val];
    }

    void pop() {
        auto& min_count = min_stack[data.back()];
        --min_count;
        if (min_count == 0) {
            min_stack.erase(data.back());
        }

        data.pop_back();
    }

    int top() {
        return data.back();
    }

    int getMin() {
        return min_stack.begin()->first;
    }

private:
    std::vector<int> data;
    std::map<int, int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    std::cout << ms.getMin() << std::endl;
    ms.pop();
    std::cout << ms.top() << std::endl;
    std::cout << ms.getMin() << std::endl;
    ms.pop();
    std::cout << ms.top() << std::endl;
    std::cout << ms.getMin() << std::endl;


}
