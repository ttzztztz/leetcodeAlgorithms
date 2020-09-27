class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        const int m = requests.size();
        for (int s = 0; s < (1 << m); s++) {
            int tmp = 0;
            vector<int> all(n, 0);
            for (int i = 0; i < m; i++) {
                if (s & (1 << i)) {
                    tmp++;
                    
                    all[requests[i][0]]++;
                    all[requests[i][1]]--;
                }
            }
            
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (all[i] != 0) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) ans = max(ans, tmp);
        }
        
        return ans;
    }
};
