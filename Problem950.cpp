class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> newDeck(deck.size(), 0);
        queue<int> idxQueue;
        sort(deck.begin(), deck.end());
        for (int i = 0; i < deck.size(); ++i) {
            idxQueue.push(i);
        }
        for (int i = 0; i < deck.size(); ++i) {
            newDeck[idxQueue.front()] = deck[i];
            idxQueue.pop();
            if (!idxQueue.empty()) {
                idxQueue.push(idxQueue.front());
                idxQueue.pop();
            }
        }
        return newDeck;
    }
};
