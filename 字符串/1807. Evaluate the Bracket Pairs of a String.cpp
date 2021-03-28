class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kv;
        for (auto& know : knowledge) {
            kv[know[0]] = know[1];
        }
        
        string ans, t;
        bool inb = false;
        for (const char ch : s) {
            if (ch == '(') {
                inb = true;
            } else if (ch == ')') {
                if (kv.count(t)) {
                    ans += kv[t];
                } else {
                    ans += "?";
                }
                t.clear();
                inb = false;
            } else {
                if (inb) t += ch;
                else ans += ch;
            }
        }
        
        return ans;
    }
};
