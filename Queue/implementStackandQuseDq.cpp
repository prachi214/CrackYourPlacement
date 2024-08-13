#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
public:
    deque<int> dq;
    // Stack operations

    // Push element onto the stack
    void pushBack(int value)
    {
        dq.push_back(value);
    }

    // Pop element from the stack
    void pop_back()
    {
        if (!dq.empty())
        {
            dq.pop_back();
        }
    }

    // Get the top element of the stack
    int top()
    {
        if (!dq.empty())
        {
            return dq.back();
        }
        return -1;
    }

    // Queue operations

    void pushback(int value)
    {
        dq.push_back(value);
    }

    // Remove element from the queue
    void popFront()
    {
        if (!dq.empty())
        {
            dq.pop_front();
        }
    }

    // Get the front element of the queue
    int front()
    {
        if (!dq.empty())
        {
            return dq.front();
        }
        return -1;
    }

    // common operations in stack and queue

    // empty
    bool isEmpty()
    {
        return dq.empty();
    }

    // size
    int size()
    {
        return dq.size();
    }
};

int main()
{

    StackQueue sq;
    // Using it as a stack
    sq.pushBack(10);
    sq.pushBack(20);
    sq.pushBack(30);

    cout << "Top element (Stack): " << sq.top() << endl;
    sq.pop_back();
    cout << "Top element after pop_back (Stack): " << sq.top() << endl;

    // Using it as a queue
    sq.pushback(40);
    sq.pushback(50);

    cout << "Front element (Queue): " << sq.front() << endl;
    sq.popFront();
    cout << "Front element after popFront (Queue): " << sq.front() << endl;
    cout << "size of queue : " << sq.size() << endl;
    cout << "is queue empty : " << sq.isEmpty() << endl;
    return 0;
}
