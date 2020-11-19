class Solution {
public:
    string decodeString(string s) {
        string ans;
        const int n = s.size();
        
        string repeat;
        vector<pair<int, int>> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                stk.emplace_back(stoi(repeat), ans.size());
                repeat.clear();
            } else if (s[i] == ']') {
                auto [rep, idx] = stk.back();
                stk.pop_back();
                
                string str = ans.substr(idx);
                for (int k = 1; k < rep; k++) ans += str;
            } else if (s[i] >= '0' && s[i] <= '9') {
                repeat += s[i];
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
