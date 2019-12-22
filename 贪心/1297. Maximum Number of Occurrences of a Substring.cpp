class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int answer = 0;
        const int N = s.size();

        for (int len = minSize; len <= maxSize; len++) {
            unordered_map<string, int> substringCount;

            for (int i = 0; i + len - 1 < N; i++) {
                const string substring = s.substr(i, len);
                substringCount[substring]++;
            }

            map<char, int> letter;
            int leftPtr = 0, rightPtr = 0;
            while (rightPtr < N) {
                while ((letter.size() > maxLetters || rightPtr - leftPtr + 1 > len) && leftPtr <= rightPtr) {
                    letter[s[leftPtr]]--;
                    if (letter[s[leftPtr]] == 0) {
                        letter.erase(s[leftPtr]);
                    }
                    leftPtr++;
                }

                letter[s[rightPtr]]++;
                if (letter.size() <= maxLetters && rightPtr - leftPtr + 1 == len) {
                    answer = max(answer, substringCount[s.substr(leftPtr, rightPtr - leftPtr + 1)]);
                }
                rightPtr++;
            }

            if (answer > 0) {
                break;
            }
        }
        return answer;
    }
};