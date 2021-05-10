class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> f(n, 0);
        for (int i = 2; i < n; i++) {
            if (f[i] == 0) {
                ans++;
                
                for (int j = 2; i * j < n; j++) f[i * j] = 1;
            }
        }
        return ans;
    }
};