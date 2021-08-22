class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        const int mi = *min_element(sums.begin(), sums.end());
        int balance = min(0, mi);
        
        multiset<int> s;
        for (int i : sums) s.insert(i - balance);
        
        vector<int> ans;
        s.erase(s.begin());
        ans.push_back(*s.begin());
        
        for (int i = 1; i < n; i++) {
            const int m = ans.size();
            for (int j = 0; j < (1 << m); j++) {
                if (j & (1 << (i - 1))) {
                    int t = 0;
                    for (int k = 0; k < m; k++) {
                        if (j & (1 << k)) t += ans[k];
                    }

                    if (s.find(t) != s.end()) s.erase(s.find(t));
                }
            }
            ans.push_back(*s.begin());
        }
        
        for (int i = 0; i < (1 << n); i++) {
            int t = 0;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) t += ans[k];
            }
            
            if (t == -balance) {
                for (int k = 0; k < n; k++) {
                    if (i & (1 << k)) ans[k] *= -1;
                }
                return ans;
            }
        }
        return ans;
    }
};