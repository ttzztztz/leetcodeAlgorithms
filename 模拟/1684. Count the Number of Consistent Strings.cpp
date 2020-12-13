class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allow(allowed.begin(), allowed.end());
        
        int ans = 0;
        for (auto& word : words) {
            bool ok = true;
            for (const char ch : word) {
                if (!allow.count(ch)) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) ans++;
        }
        return ans;
    }
};
