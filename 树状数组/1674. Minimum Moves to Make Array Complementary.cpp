class BIT {
public:
    BIT() {
        memset(data, 0, sizeof data);
    }
    int data[200005];
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int x) {
        int ans = 0;
        if (x < 0) return 0;
        while (x) {
            ans += data[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void inc(int x, int y) {
        while (x && x <= 200001) {
            data[x] += y;
            x += lowbit(x);
        }
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        const int n = nums.size(), m = n / 2;
        typedef pair<int, int> PII;
        map<int, vector<int>> ttl;
        vector<PII> pairs;
        for (int i = 0; i < m; i++) {
            pairs.emplace_back(nums[i], nums[n - i - 1]);
        }
        
        for (int i = 0; i < m; i++) {
            auto [fir, sec] = pairs[i];
            ttl[fir + sec].emplace_back(i);
            r.inc(min(fir, sec), 1);
        }
        
        int ans = n;
        for (auto [sum, vec] : ttl) {
            const int vec_size = vec.size();
            for (int i : vec) r.inc(min(pairs[i].first, pairs[i].second), -1);
            
            if (limit * 2 >= sum) {
                int ones = 0, seconds = 0;
                
                const int a = l.query(sum - limit - 1);
                const int b = r.query(200001) - r.query(sum - 1);
                
                seconds = a + b;
                ones = m - vec_size - seconds;
                ans = min(ans, ones + seconds * 2);
            }
            
            for (int i : vec) l.inc(max(pairs[i].first, pairs[i].second), 1);
        }
        return ans;
    }
private:
    BIT l, r;
};
