// Implement two stacks in an array

class twoStacks
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    twoStacks(int size = 100)
    {
        arr = new int[size];
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top1 == (size / 2) + 1)
        {
            return;
        }
        else
        {
            top1++;
            arr[top1] = x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {

        if (top2 == (size / 2) - 1)
        {
            return;
        }
        else
        {
            top2--;
            arr[top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1)
        {
            return -1;
        }
        else
        {
            int x = arr[top1--];
            return x;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == size)
        {
            return -1;
        }
        else
        {
            int x = arr[top2++];
            return x;
        }
    }
};