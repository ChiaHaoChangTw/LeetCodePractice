class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        for (auto& token: tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                numStack.push(stoi(token));
                continue;
            }
            int num2 = numStack.top();
            numStack.pop();
            if (token == "+") {
                numStack.top() = numStack.top() + num2;
            } else if (token == "-") {
                numStack.top() = numStack.top() - num2;
            } else if (token == "*") {
                numStack.top() = numStack.top() * num2;
            } else {
                numStack.top() = numStack.top() / num2;
            }
        }
        return numStack.top();
    }
};

// stack
// time O(n)
// space O(n)

