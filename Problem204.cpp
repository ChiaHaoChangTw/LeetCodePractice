#include<vector>
#include<iostream>

using namespace std;

class Solution{
public:
    int countPrimes(int n){
        if(n <= 2){return 0;}
        vector<bool> isPrime(n, true);
        int count = 1;
        for(int i = 3; i < n; i += 2){
            if(isPrime[i]){
                ++count;
                for(int j = 3; i * j < n; j += 2){isPrime[i * j] = false;}
            }
        }
        return count;
    }
};

int main(){
	Solution* solution = new Solution();
	cout << solution->countPrimes(10) << " [expected: 4]" << endl;
	cout << solution->countPrimes(0) << " [expected: 0]" << endl;
	cout << solution->countPrimes(1) << " [expected: 0]" << endl;
	cout << solution->countPrimes(110) << " [expected: 29]" << endl;
	return 0;
}
