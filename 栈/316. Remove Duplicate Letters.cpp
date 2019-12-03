class Solution {
public:
    string removeDuplicateLetters(string s) {
        string answer;
        vector<int> statics(26, 0);
        vector<bool> appear(26, 0);
        for (const char& ch : s) {
            statics[ch - 'a']++;
        }

        for (const char& ch : s) {
            statics[ch - 'a']--;
            if (appear[ch - 'a']) {
                continue;
            }

            while (answer.size() > 0 && answer.back() > ch && statics[answer.back() - 'a']) {
                appear[answer.back() - 'a'] = false;
                answer.pop_back();
            }

            appear[ch - 'a'] = true;
            answer.push_back(ch);
        }

        return answer;
    }
};