class Solution {
public:
    int countVowelStrings(int n) {
        typedef long long ll;
        
        vector<ll> f(6, 0);
        for (int i = n; i >= 0; i--) {
            vector<ll> g(6, 0);
            for (int j = 0; j < 5; j++) {
                if (i == n) {
                    g[j] = 1;
                    continue;
                }

                g[j] = f[j];
                for (int k = j + 1; k < 5; k++) g[j] += f[k];
            }
            f = g;
        }
        
        return f[0];
    }
};