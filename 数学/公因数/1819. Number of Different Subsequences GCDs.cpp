class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        const int n = nums.size();
        memset(f, 0, sizeof f);

        mx = *max_element(nums.begin(), nums.end());
        for (int i : nums) f[i] = true;
        
        int ans = 0;
        for (int i = 1; i <= mx; i++) {
            if (ok(i)) ans++;
        }
        return ans;
    }
private:
    unordered_set<int> all;
    bool f[200005];
    int mx;
    bool ok(int num) {
        int t = 0;
        for (int i = 1; i * num <= mx; i++) {
            if (!f[num * i]) continue;
            
            if (t == 0) t = i;
            else t = __gcd(t, i);
        }
        return t == 1;
    }
};
