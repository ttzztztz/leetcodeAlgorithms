class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int answer = 0;
        const int N = words.size();
        const int mask = (1 << N) - 1;
        vector<int> letterStatics(26, 0);
        for (const char& ch : letters) {
            letterStatics[ch - 'a']++;
        }

        for (int i = 0; i <= mask; i++) {
            vector<int> letterStaticsCopy = letterStatics;
            bool invalidState = false;
            int currentScore = 0;

            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {

                    for (int k = 0; k < words[j].size(); k++) {

                        const int charState = words[j][k] - 'a';

                        letterStaticsCopy[charState]--;
                        if (letterStaticsCopy[charState] < 0) {
                            invalidState = true;
                            break;
                        } else {
                            currentScore += score[charState];
                        }

                    }
                }

                if (invalidState) {
                    break;
                }
            }

            if (!invalidState) {
                answer = max(answer, currentScore);
            }
        }

        return answer;
    }
};