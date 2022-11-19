class MyStack
{
    private:
        queue<int> Queue;
    public:
        MyStack() {}

    void push(int x)
    {
        Queue.push(x);
        if (!Queue.empty())
        {
            for (int i = 0; i < Queue.size() - 1; i++)
            {
                Queue.push(Queue.front());
                Queue.pop();
            }
        }
    }

    int pop()
    {
        int value = Queue.front();
        Queue.pop();
        return value;
    }

    int top()
    {
        return Queue.front();
    }

    bool empty()
    {
        return Queue.empty();
    }
};

/**
 *Your MyStack object will be instantiated and called as such:
 *MyStack* obj = new MyStack();
 *obj->push(x);
 *int param_2 = obj->pop();
 *int param_3 = obj->top();
 *bool param_4 = obj->empty();
 */