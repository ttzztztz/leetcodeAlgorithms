class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> answer;

        unordered_map<int, int> stateCountMap;
        for (int i = 0; i < words.size(); i++) {
            const string& word = words[i];
            int state = 0;

            for (int j = 0; j < word.size(); j++) {
                state |= 1 << (word[j] - 'a');
            }

            stateCountMap[state]++;
        }

        for (const string& puzzle : puzzles) {
            int state = 0, tempAnswer = 0;
            for (int i = 0; i < puzzle.size(); i++) {
                state |= 1 << (puzzle[i] - 'a');
            }

            for (int i = state; i; i = (i - 1) & state) {
                if (i & (1 << (puzzle[0] - 'a'))) {
                    tempAnswer += stateCountMap[i];
                }
            }

            answer.push_back(tempAnswer);
        }

        return answer;
    }
};