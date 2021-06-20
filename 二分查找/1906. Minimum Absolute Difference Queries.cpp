class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        const int q = queries.size(), n = nums.size();
        vector<int> ans(q);
        map<int, vector<int>> hmap;
        for (int i = 0; i < n; i++) {
            hmap[nums[i]].push_back(i);
        }
        
        for (int i = 0; i < q; i++) {
            const int l = queries[i][0], r = queries[i][1];
            ans[i] = query(l, r, hmap);
        }
        return ans;
    }
private:
    int query(int l, int r, map<int, vector<int>>& hmap) {
        int ans = 10005;
        
        int lastk = -1;
        for (auto& [k, v] : hmap) {
            auto it1 = lower_bound(v.begin(), v.end(), l);
            auto it2 = upper_bound(v.begin(), v.end(), r);
            
            if (it1 == it2) continue;            
            if (lastk != -1) ans = min(ans, k - lastk);
            lastk = k;
        }
        
        if (ans >= 10005 || ans == 0) return -1;
        else return ans;
    }
};
