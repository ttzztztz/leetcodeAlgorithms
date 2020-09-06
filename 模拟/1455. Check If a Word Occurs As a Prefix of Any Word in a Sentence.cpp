class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int answer = -1;
        vector<string> words;
        string tmp;
        for (const char ch : sentence) {
            if (ch == ' ') {
                words.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(ch);
            }
        }
        if (!tmp.empty()) {
            words.push_back(tmp);
            tmp.clear();
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(searchWord) == 0) {
                answer = i + 1;
                break;
            }
        }
        
        return answer;
    }
};
