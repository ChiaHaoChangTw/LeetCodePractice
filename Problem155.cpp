class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minCountStack.empty() || minCountStack.top().first > val) {
            minCountStack.push(make_pair(val, 1));
        } else if (minCountStack.top().first == val) {
            ++minCountStack.top().second;
        }
        regularStack.push(val);
    }
    
    void pop() {
        if (minCountStack.top().first == regularStack.top()) {
            if (minCountStack.top().second == 1) {
                minCountStack.pop();
            } else {
                --minCountStack.top().second;
            }
        }
        regularStack.pop();
    }
    
    int top() {
        return regularStack.top();
    }
    
    int getMin() {
        return minCountStack.top().first;
    }

private:
    stack<int> regularStack;
    stack<pair<int, int>> minCountStack;
};

// additional stack to store min and its count
// time O(1)
// space O(n)

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

