#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int> nums, int target){
		unordered_map<int, int> uMap;
        	vector<int> result;
        	for(int i = 0; i < nums.size(); ++i){
        		if(uMap.find(target - nums[i]) != uMap.end()){
        			result.push_back(i), result.push_back(uMap[target - nums[i]]);
        			break;
            		}
        		uMap[nums[i]] = i;
        	}
        return result;
	}
};

int main(){
	Solution* solution = new Solution();
	cout << solution->twoSum({2,7,11,15}, 9)[0] << "," << solution->twoSum({2,7,11,15}, 9)[1]  << endl;
	cout << solution->twoSum({3,2,4}, 6)[0] << "," << solution->twoSum({3,2,4}, 6)[1] << endl;
	cout << solution->twoSum({3,3}, 6)[0] << "," << solution->twoSum({3,3}, 6)[1] << endl;
	return 0;
}
