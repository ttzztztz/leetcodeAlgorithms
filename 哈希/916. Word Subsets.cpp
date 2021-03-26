class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> f(26, 0);
        for (auto& b : B) {
            vector<int> cur(26, 0);
            for (auto& ch : b) {
                cur[ch - 'a']++;
            }
            
            for (int i = 0; i < 26; i++) {
                f[i] = max(f[i], cur[i]);
            }
        }
        vector<string> ans;
        for (auto& a : A) {
            vector<int> cur(26, 0);
            for (auto& ch : a) {
                cur[ch - 'a']++;
            }
            
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cur[i] < f[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(a);
        }
        return ans;
    }
};
