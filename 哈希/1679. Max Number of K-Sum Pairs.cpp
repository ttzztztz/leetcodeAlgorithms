class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> a;
        for (int i : nums) a[i]++;
        
        int ans = 0;
        unordered_set<int> visited;
        for (auto [val, cnt] : a) {
            if (visited.count(val)) continue;
            visited.insert(val), visited.insert(k - val);
            
            if (val == k - val) {
                ans += cnt / 2;
            } else {
                const int t = a.count(k - val) ? a[k - val] : 0;
                ans += min(cnt, t);
            }
        }
        
        return ans;
    }
};
