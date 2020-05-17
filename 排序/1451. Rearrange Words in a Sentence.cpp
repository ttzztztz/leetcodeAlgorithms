class Solution {
public:
    string arrangeWords(string text) {
        text[0] = text[0] - 'A' + 'a';
        vector<string> str;
        string cur;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                str.push_back(cur);
                cur.clear();
            } else {
                cur += text[i];
            }
        }
        str.push_back(cur);
        cur.clear();
        
        string answer;
        stable_sort(str.begin(), str.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1.size() < $2.size();
        });
        for (int i = 0; i < str.size(); i++) {
            string& s = str[i];
            if (i == 0) {
                s[i] = s[i] - 'a' + 'A';
                answer += s;
            } else {
                answer += " " + s;
            }
        }
        return answer;
    }
};
