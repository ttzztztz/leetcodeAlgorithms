class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<pair<int, int>> stateArr;
        int N = arr.size();

        for (int i = 0; i < arr.size(); i++) {
            const string& str = arr[i];
            int state = 0;

            bool invalidState = false;
            for (int j = 0; j < str.size(); j++) {
                if (state & (1 << (str[j] - 'a'))) {
                    invalidState = true;
                    break;
                }
                state |= 1 << (str[j] - 'a');
            }

            if (invalidState) {
                N--;
                continue;
            }

            stateArr.push_back(std::make_pair(state, str.size()));
        }

        int answer = 0;
        for (int i = 0; i < (1 << N); i++) {
            int currentState = 0, currentAnswer = 0;
            bool valid = true;

            for (int j = 0; j < N; j++) {
                if ((i & (1 << j)) == 0) {
                    continue;
                }
                if ((stateArr[j].first & currentState) == 0) {
                    currentState |= stateArr[j].first;
                    currentAnswer += stateArr[j].second;
                } else {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                answer = std::max(answer, currentAnswer);
            }
        }

        return answer;
    }
};