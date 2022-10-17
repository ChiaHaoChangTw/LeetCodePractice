class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        
        generateAdjMap(wordList, beginWord);
        queue<string> beginQueue, endQueue;
        beginQueue.push(beginWord), endQueue.push(endWord);
        int beginLevel = 0, endLevel = 0;
        unordered_set<string> beginVisited, endVisited;
        
        while(!beginQueue.empty() && !endQueue.empty()) {
            if(bfsMatch(beginQueue, beginLevel, beginVisited, endVisited)) {
                return beginLevel + endLevel;
            }
            if(bfsMatch(endQueue, endLevel, endVisited, beginVisited)) {
                return beginLevel + endLevel;
            }
        }
        
        return 0;
    }
    
private:
    unordered_map<string, vector<string>> adjMap;
    
    void generateAdjMap(vector<string>& wordList, string& beginWord) {
        for(auto& word: wordList) {
            for(int i = 0; i < word.size(); ++i) {
                string genericWord = word.substr(0, i) + '*' + word.substr(i + 1);
                adjMap[genericWord].push_back(word);
            }
        }
        for(int i = 0; i < beginWord.size(); ++i) {
            string genericWord = beginWord.substr(0, i) + '*' + beginWord.substr(i + 1);
            adjMap[genericWord].push_back(beginWord);
        }
    }
    
    bool bfsMatch(queue<string>& queue, int& level, unordered_set<string>& selfVisited, 
                  unordered_set<string>& otherVisited) {
        int currLevelSize = queue.size();
        for(int k = 0; k < currLevelSize; ++k) {
            string currString = queue.front();
            queue.pop();
            if(selfVisited.find(currString) != selfVisited.end()) {
                continue;
            }
            selfVisited.insert(currString);
            unordered_set<string> adjWords;
            getAdjWords(currString, adjWords);
            for(auto& adjWord: adjWords) {
                if(otherVisited.find(adjWord) != otherVisited.end()) {
                    ++level;
                    return true;
                }
                if(selfVisited.find(adjWord) == selfVisited.end()) {
                    queue.push(adjWord);
                }
            }
        }
        ++level;
        return false;
    }
    
    void getAdjWords(string& currString, unordered_set<string>& adjWords) {
        for(int i = 0; i < currString.size(); ++i) {
            string genericWord = currString.substr(0, i) + '*' + currString.substr(i + 1);
            for(auto& adjWord: adjMap[genericWord]) {
                if(adjWord == currString) {
                    continue;
                }
                adjWords.insert(adjWord);
            }
        }
    }
};

