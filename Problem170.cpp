class TwoSum {
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        ++countMap[number];
    }
    
    bool find(int value) {
        for (auto it: countMap) {
            long target = (long) value - it.first;
            if (target == it.first && it.second >= 2) {
                return true;
            }
            if (target != it.first && countMap.find(target) != countMap.end()) {
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<int, int> countMap;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

// hash map
// time add O(1) find O(n)
// space O(n)

