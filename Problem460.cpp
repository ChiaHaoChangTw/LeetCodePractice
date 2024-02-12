class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!keyFreqNodeMap.count(key)) {
            return -1;
        }
        const int f = keyFreqNodeMap[key].first;
        const auto it = keyFreqNodeMap[key].second;
        const int value = it->second;
        freqListMap[f].erase(it);
        if (freqListMap[f].empty()) {
            freqListMap.erase(f);
            minFreq += minFreq == f;
        }
        insert(key, f + 1, value);
        return value;
    }
    
    void put(int key, int value) {
        if (keyFreqNodeMap.count(key)) {
            keyFreqNodeMap[key].second->second = value;
            get(key);
            return;
        }
        if (cap == keyFreqNodeMap.size()) {
            keyFreqNodeMap.erase(freqListMap[minFreq].front().first);
            freqListMap[minFreq].pop_front();
            if (freqListMap[minFreq].empty()) {
                freqListMap.erase(minFreq);
            }
        }
        minFreq = 1;
        insert(key, 1, value);
    }

private:
    unordered_map<int, list<pair<int, int>>> freqListMap;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> keyFreqNodeMap;
    int cap = 0;
    int minFreq = 0;

    void insert(int key, int frequency, int value) {
        freqListMap[frequency].push_back({key, value});
        keyFreqNodeMap[key] = {frequency, --freqListMap[frequency].end()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 2 hash maps
// STL list
// time: O(1)
// space: O(n)

