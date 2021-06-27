class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int n = nums.size();
        
        memset(data, 0, sizeof data);
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = query(nums[i] - 1);
            inc(nums[i], 1);
        }
        return ans;
    }
private:
    const int base = 1e4+1, maxn = 50000;
    int data[50001];
    
    int lowbit(int x) {
        return x&(-x);
    }
    
    int query(int u) {
        u += base;
        
        int ans = 0;
        while (u) {
            ans += data[u];
            u -= lowbit(u);
        }
        return ans;
    }
    
    void inc(int u, int v) {
        u += base;
        
        while (u && u < maxn) {
            data[u] += v;
            u += lowbit(u);
        }
    }
};