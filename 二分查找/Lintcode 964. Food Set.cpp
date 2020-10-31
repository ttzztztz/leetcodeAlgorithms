class Solution {
public:
    /**
     * @param lunch: an array that contains each lunch food's calories and value
     * @param dinner: an array that contains each dinner food's calories and value
     * @param T: the minest limit value
     * @return: return the min calories
     */
    int getMinCalories(vector<vector<int>> &lunch, vector<vector<int>> &dinner, int T) {
        if (T == 0) return 0;

        const int n = lunch.size(), m = dinner.size();
        sort(lunch.begin(), lunch.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[1] < $2[1];
        });
        
        sort(dinner.begin(), dinner.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[1] < $2[1];
        });
        
        int ans = numeric_limits<int>::max();
        vector<int> mi(m - 1, 0);
        mi[m - 1] = dinner[m - 1][0];
        
        for (int i = m - 2; i >= 0; i--) {
            mi[i] = min(mi[i + 1], dinner[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            const int hot = lunch[i][0], good = lunch[i][1];
            const int v = T - good;
            
            int l = 0, r = m - 1;
            while (l <= r) {
                const int mid = (l + r) >> 1;
                
                if (dinner[mid][1] < v) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            if (l < m) {
                ans = min(ans, hot + mi[l]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (lunch[i][1] >= T) {
                ans = min(ans, lunch[i][0]);
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (dinner[i][1] >= T) {
                ans = min(ans, dinner[i][0]);
            }
        }
        
        if (ans == numeric_limits<int>::max()) return -1;
        else return ans;
    }
};
