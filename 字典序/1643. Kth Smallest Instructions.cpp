class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        string ans;
        int h = destination[1], v = destination[0];
        const int n = h + v;
        
        typedef long long ll;
        ll f[31][31];
        memset(f, 0, sizeof f);
        
        f[0][0] = 1;
        for (int i = 1; i <= 30; i++) for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                f[i][j] = 1;
                continue;
            }
            
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
        
        while (k && ans.size() < n) {
            // C(h + v - 1, v)
            const ll cur = (v == 0 ? 0 : f[h + v - 1][v]);
            
            if (k > cur && v > 0) {
                k -= cur;
                ans += "V";
                v--;
            } else {
                ans += "H";
                h--;
            }
        }
        return ans;
    }
};