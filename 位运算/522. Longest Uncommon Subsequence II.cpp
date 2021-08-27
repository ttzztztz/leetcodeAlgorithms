class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        const int n = strs.size();
        unordered_map<string, int> appear;
        for (int i = 0; i < n; i++) {
            for (auto& sub : subseqs(strs[i])) appear[sub]++;
        }
        
        for (int i = 0; i < n; i++) {
            for (auto& sub : subseqs(strs[i])) appear[sub]--;
            
            for (auto& sub : subseqs(strs[i])) {
                if (appear[sub] == 0) {
                    ans = max<int>(ans, sub.size());
                }
            }
            
            for (auto& sub : subseqs(strs[i])) appear[sub]++;
        }
        return ans;
    }
private:
    vector<string> subseqs(const string& str) {
        const int m = str.size();
            
        vector<string> ans;
        for (int j = 1; j < (1 << m); j++) {
            string t;
            for (int k = 0; k < m; k++) {
                if (j & (1 << k)) t += str[k];
            }
            ans.push_back(t);
        }
        return ans;
    }
};
