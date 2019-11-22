class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int N = s.size();
        vector<int> answer;
        if (0 == words.size() || 0 == s.size()) {
            return answer;
        }
        const int wordsLen = words.size(), wordLen = words[0].size();
        if (s.size() < wordsLen * wordLen) {
            return answer;
        }

        unordered_map<string, int> wordMap;
        unordered_set<char> beginChar;
        vector<int> appearCount;
        int wordMapIndex = 0;
        for (const string& word : words) {
            if (wordMap.count(word)) {
                appearCount[wordMap[word]]++;
            } else {
                wordMap[word] = wordMapIndex;
                appearCount.push_back(1);
                wordMapIndex++;
            }
            beginChar.insert(word[0]);
        }

        int leftPtr = 0, rightPtr = wordsLen * wordLen - 1;
        while (rightPtr < N) {
            const char leftChar = s[leftPtr];
            if (!beginChar.count(leftChar)) {
                leftPtr++, rightPtr++;
                continue;
            }

            vector<int> appear = appearCount;
            bool invalid = false;
            for (int i = 0; i < wordsLen; i++) {
                string temp;
                for (int j = 0; j < wordLen; j++) {
                    temp += s[leftPtr + i * wordLen + j];
                }

                if (!wordMap.count(temp)) {
                    invalid = true;
                    break;
                }
                const int index = wordMap[temp];
                appear[index]--;
                if (appear[index] < 0) {
                    invalid = true;
                    break;
                }
            }

            if (invalid) {
                leftPtr++, rightPtr++;
                continue;
            }

            bool allVisited = true;
            for (int i = 0; i < wordMapIndex; i++) {
                if (appear[i]) {
                    allVisited = false;
                    break;
                }
            }
            if (allVisited) {
                answer.push_back(leftPtr);
            }
            leftPtr++, rightPtr++;
        }
        return answer;
    }
};