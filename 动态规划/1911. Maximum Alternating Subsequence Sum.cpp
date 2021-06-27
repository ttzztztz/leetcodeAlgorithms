class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        memset(f, 0xff, sizeof f);
        arr = nums;
        n = arr.size();
        
        return dfs(0, 0);
    }
private:
    typedef long long ll;
    
    vector<int> arr;
    int n;
    ll f[100005][2];
    
    ll dfs(int idx, int last) {
        if (idx == n) return 0;
        ll& val = f[idx][last];
        if (val != -1) return val;
        
        ll ans = dfs(idx + 1, last);
        if (last == 0) ans = max(ans, dfs(idx + 1, last ^ 1) + arr[idx]);
        else ans = max(ans, dfs(idx + 1, last ^ 1) - arr[idx]);
        return val = ans;
    }
};