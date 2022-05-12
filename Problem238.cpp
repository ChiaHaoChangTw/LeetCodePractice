#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	vector<int> productExceptSelf(vector<int>& nums){
        	vector<int> result(nums.size(), 1);
        	int left = 1, right = 1;
        	for(int i = 1; i < nums.size(); ++i){
            		left *= nums[i - 1];
            		result[i] *= left;
            		right *= nums[nums.size() - i];
            		result[nums.size() - i - 1] *= right;
        	}
        	return result;
    	}
};

int main(){
	Solution* solution = new Solution();
	vector<int> vec1 = {1,2,3,4};
	vector<int> vec2 = {-1,1,0,-3,3};
	vector<int> res1 = solution->productExceptSelf(vec1);
	vector<int> res2 = solution->productExceptSelf(vec2);
	for(auto& res: res1){
		cout << res << ",";
	}
	cout << endl;
	cout << "[expected: 24,12,8,6]" << endl;
	for(auto& res: res2){
		cout << res << ",";
	}
	cout << endl;
	cout << "[expected: 0,0,9,0,0]" << endl;
	return 0;
}
