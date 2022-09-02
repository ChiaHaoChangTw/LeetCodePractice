class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lastFruit = -1;
        int secondLstFruit = -1;
        int lastFruitCount = 0;
        int currMax = 0;
        int result = 0;
        
        for(auto& fruit: fruits) {
            if(fruit == lastFruit || fruit == secondLstFruit) {
                ++currMax;
            }
            else {
                currMax = lastFruitCount + 1;
            }
            
            if(fruit == lastFruit) {
                ++lastFruitCount;
            }
            else {
                secondLstFruit = lastFruit;
                lastFruit = fruit;
                lastFruitCount = 1;
            }
            
            result = max(result, currMax);
        }
        
        return result;
    }
};

// hash, sliding window
// count each fruit in the window

// counts

// Time: O(n)
// Space: O(1)
