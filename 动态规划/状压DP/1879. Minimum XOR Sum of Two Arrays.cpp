class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(f, 0xff, sizeof f);
        n = nums1.size();
        a = nums1, b = nums2;
        
        return dfs(0, 0);
    }
private:
    int f[15][(1 << 14) + 5];
    int n;
    vector<int> a, b;
    
    int dfs(int idx, int state) {
        if (idx == n) return 0;
        int& val = f[idx][state];
        if (val != -1) return val;
        
        int ans = numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            if (state & (1 << j)) continue;
            
            ans = min(ans, (a[idx] ^ b[j]) + dfs(idx + 1, state | (1 << j)));
        }
        return val = ans;
    }
};