class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (pushStk.empty()) {
            front = x;
        }
        pushStk.push(x);
    }
    
    int pop() {
        if (popStk.empty()) {
            while (!pushStk.empty()) {
                popStk.push(pushStk.top());
                pushStk.pop();
            }
        }
        int val = popStk.top();
        popStk.pop();
        return val;
    }
    
    int peek() {
        if (!popStk.empty()) {
            return popStk.top();
        }
        return front;
    }
    
    bool empty() {
        return pushStk.empty() && popStk.empty();
    }

private:
    stack<int> pushStk;
    stack<int> popStk;
    int front = -1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

