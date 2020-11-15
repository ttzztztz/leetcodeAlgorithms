class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int n = code.size();
        vector<int> ans(n, 0);
        
        if (k == 0) return ans;
        for (int i = 0; i < n; i++) {
            if (k > 0) {
                for (int j = 0; j < k; j++) {
                    ans[i] += code[(i + j + 1) % n];
                }
            } else {
                for (int j = 0; j < -k; j++) {
                    const int t = (i - j - 1 + n) % n;
                    ans[i] += code[t];
                }
            }
        }
        
        return ans;
    }
};
