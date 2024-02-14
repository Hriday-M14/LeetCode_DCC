// Implement Queue using Stacks

class MyQueue {
    stack<int> back;
    stack<int> front;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        back.push(x);
    }
    
    int pop() {
        int FrontElement = 0;
        if(!front.empty())
        {
            FrontElement = front.top();
            front.pop();
        }
        else
        {
            while(!back.empty())
            {
                front.push(back.top());
                back.pop();
            }
            FrontElement = front.top();
            front.pop();
        }
        return FrontElement;
    }
    
    int peek() {
        int FrontElement = 0;
        if(!front.empty())
        {
            FrontElement = front.top();
        }
        else
        {
            while(!back.empty())
            {
                front.push(back.top());
                back.pop();
            }
            FrontElement = front.top();
        }
        return FrontElement;
    }
    
    bool empty() {
        return (front.empty() && back.empty());
    }
};