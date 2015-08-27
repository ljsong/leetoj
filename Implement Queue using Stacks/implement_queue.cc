#include <deque>
#include <iostream>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue
    void push(int x) {
        stak2.push_front(x);
    }

    // Removes the element from in front of queue
    void pop(void) {
        if(stak1.empty()) {
            while(!stak2.empty()) {
                int value = stak2.front();
                stak2.pop_front();
                stak1.push_front(value);
            }
        }

        if(!stak1.empty()) {
            stak1.pop_front();
        }
    }

    // Get the front element.
    int peek(void) {
        if(stak1.empty()) {
            while(!stak2.empty()) {
                int value = stak2.front();
                stak2.pop_front();
                stak1.push_front(value);
            }
        }

        return stak1.front();
    }

    // Return whether the queue is empty
    bool empty(void) {
        return stak1.empty() && stak2.empty();
    }

private:
    deque<int> stak1;
    deque<int> stak2;
};

int main() {
    Queue queue;
    queue.push(5);
    queue.push(6);
    std::cout << queue.empty() << std::endl;
    std::cout << "first element is: " << queue.peek() << std::endl;

    queue.pop();
    std::cout << "first element after pop: " << queue.peek() << std::endl;
    queue.pop();
    std::cout << "queue is empty? " << (queue.empty() ? "[true]" : "[false]") << std::endl;
    
    return 0;
}
