class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int numZero = 0;
        int numOne = 0;
        for (const auto &student: students) {
            numZero += student == 0;
            numOne += student == 1;
        }
        for (int i = 0; i < sandwiches.size(); ++i) {
            if (sandwiches[i] == 0 && numZero == 0 ||
                    sandwiches[i] == 1 && numOne == 0) {
                return sandwiches.size() - i;
            }
            numZero -= sandwiches[i] == 0;
            numOne -= sandwiches[i] == 1;
        }
        return 0;
    }
};

// counting
// time: O(n + m)
// space: O(1)

