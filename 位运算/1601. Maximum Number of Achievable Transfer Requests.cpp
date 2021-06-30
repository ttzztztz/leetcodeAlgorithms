class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        const int m = requests.size();
        
        int ans = 0;
        for (int i = 0; i < (1 << m); i++) {
            vector<int> t(n, 0);
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    t[requests[j][0]]++, t[requests[j][1]]--;
                }
            }
            
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (t[i] != 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans = max(ans, __builtin_popcount(i));
        }
        return ans;
    }
};