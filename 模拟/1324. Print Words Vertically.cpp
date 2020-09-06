class Solution {
public:
    vector<string> split(const string& s) {
        vector<string> splited;
        string temp;
        for (const char ch : s) {
            if (ch != ' ') {
                temp += ch;
            } else {
                splited.push_back(temp);
                temp.clear();
            }
        }
        splited.push_back(temp);
        return splited;
    }
    vector<string> printVertically(string s) {
        int maxlen = 0;
        vector<string> splited = split(s);
        for (const string& str : splited) maxlen = max(maxlen, (int) str.size());
        
        vector<string> answer(maxlen, "");
        for (const string& str : splited) {
            for (int i = 0; i < maxlen; i++) {
                if (i < str.size()) {
                    answer[i].push_back(str[i]);
                } else {
                    answer[i].push_back(' ');
                }
            }
        }
        
        bool isTail = true;
        for (int j = 0; j < answer.size(); j++) {
            for (int i = answer[j].size() - 1; i >= 0; i--) {
                if (isTail && answer[j][i] == ' ') {
                    answer[j].erase(answer[j].begin() + i);
                } else if (answer[j][i] != ' ') {
                    break;
                }
            }
        }
        
        return answer;
    }
};
