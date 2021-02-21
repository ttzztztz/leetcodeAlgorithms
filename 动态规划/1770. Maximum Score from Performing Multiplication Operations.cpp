class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(f, 0xff, sizeof f);
        this->nums = nums, this->muls = multipliers;
        
        return dfs(0, 0);
    }
private:
    typedef long long ll;
    ll f[1005][1005];
    vector<int> nums, muls;
    
    ll dfs(int pick, int front_pick) {
        if (pick == muls.size()) return 0;
        ll& val = f[pick][front_pick];
        if (val != -1) return val;
        
        ll ans = numeric_limits<int>::min();
        // pick front
        ans = max(ans, 1ll * muls[pick] * nums[front_pick] + dfs(pick + 1, front_pick + 1));
        // pick end
        const int t = pick - front_pick;
        ans = max(ans, 1ll * muls[pick] * nums[nums.size() - 1 - t] + dfs(pick + 1, front_pick));
        return val = ans;
    }
};
