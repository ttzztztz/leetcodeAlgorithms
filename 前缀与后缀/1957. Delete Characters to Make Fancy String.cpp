class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        vector<int> t;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            if (t.empty() || s[i] != ans.back() || (s[i] == ans.back() && t.back() + 1 < 3)) {
                if (t.empty() || s[i] != ans.back()) t.push_back(1);
                else t.push_back(t.back() + 1);
                
                ans += s[i];
            }
        }
        return ans;
    }
};