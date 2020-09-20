class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        const int mod = 1e9+7;
        init();
        long long ans = 0;
        for (auto& r : requests) {
            inc(r[0] + 1, 1);
            inc(r[1] + 2, -1);
        }
        
        multiset<int> s;
        for (int i = 1; i <= 100001; i++) {
            const int k = query(i);
            if (k > 0) s.insert(k);
        }
        
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--) {
            const int t = nums[i];
            if (s.empty()) break;
            auto it = --s.end();
            
            ans = (ans + t * (*it)) % mod;
            s.erase(it);
        }
        
        return ans;
    }
private:
    int data[100005];
    void init() {
        memset(data, 0, sizeof data);
    }
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int u) {
        int ans = 0;
        while (u) {
            ans += data[u];
            u -= lowbit(u);
        }
        return ans;
    }
    void inc(int u, int v) {
        while (u && u <= 100000) {
            data[u] += v;
            u += lowbit(u);
        }
    }
};
