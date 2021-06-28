class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        if (n <= 1) return n;
        
        vector<int> l(n, 1), r(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) l[i] = 1 + l[i - 1];
            else l[i] = 1;
        }
        
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) r[i] = 1 + r[i + 1];
            else r[i] = 1;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) ans += max(l[i], r[i]);
        return ans;
    }
};