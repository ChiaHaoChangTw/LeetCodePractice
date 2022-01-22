#include<iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int run = getNext(n), walk = n;
        while(run != 1){
            if(run == walk){return false;}
            run = getNext(getNext(run)), walk = getNext(walk);
        }
        return true;
    }
private:
    int getNext(int n){
        int result = 0;
        while(n > 0){
            result += ((n % 10) * (n % 10));
            n /= 10;
        }
        return result;
    }
};

int main(){
	Solution* solution = new Solution();
	cout << solution->isHappy(19) << " [expected: 1]" << endl;
	cout << solution->isHappy(2) << " [expected: 0]" << endl;
	return 0;
}
