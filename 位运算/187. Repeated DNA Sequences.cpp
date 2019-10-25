class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int MAX_VALID_STATE = (1 << 20) - 1;
        bool appearState[MAX_VALID_STATE + 5];
        bool visitedState[MAX_VALID_STATE + 5];
        std::memset(appearState, 0, sizeof(appearState));
        std::memset(visitedState, 0, sizeof(visitedState));

        vector<string> answer;
        int currentState = 0;
        for (int i = 0; i < 10; i++) {
            currentState <<= 2;
            currentState &= MAX_VALID_STATE;
            currentState |= getState(s[i]);
        }
        appearState[currentState] = true;

        for (int i = 10; i < s.size(); i++) {
            currentState <<= 2;
            currentState &= MAX_VALID_STATE;
            currentState |= getState(s[i]);

            if (appearState[currentState] && !visitedState[currentState]) {
                answer.push_back(stateToString(currentState));
                visitedState[currentState] = true;
            } else {
                appearState[currentState] = true;
            }
        }

        return answer;
    }
    int getState(const char c) {
        if (c == 'A') {
            return 0;
        } else if (c == 'G') {
            return 1;
        } else if (c == 'T') {
            return 2;
        } else {
            return 3;
        }
    }
    string stateToString(int state) {
        string result;

        for (int i = 0; i < 10; i++) {
            int last = state & 3;

            if (last == 0) {
                result.push_back('A');
            } else if (last == 1) {
                result.push_back('G');
            } else if (last == 2) {
                result.push_back('T');
            } else {
                result.push_back('C');
            }

            state >>= 2;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};