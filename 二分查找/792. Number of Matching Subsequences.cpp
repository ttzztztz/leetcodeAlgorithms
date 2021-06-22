class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<char, vector<int>> idx;
        
        const int n = s.size(), m = words.size();
        for (int i = 0; i < n; i++) idx[s[i]].push_back(i);
        
        for (int i = 0; i < m; i++) {
            bool ok = true;
            
            int t = 0;
            for (int j = 0; j < words[i].size(); j++) {
                const char cur = words[i][j];
                auto it = lower_bound(idx[cur].begin(), idx[cur].end(), t);
                
                if (it == idx[cur].end()) {
                    ok = false;
                    break;
                } else {
                    t = *it + 1;
                }
            }
            
            if (ok) ans++;
        }
        return ans;
    }
};