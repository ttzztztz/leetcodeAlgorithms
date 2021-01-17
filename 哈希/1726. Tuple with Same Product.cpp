class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        
        unordered_map<int, int> pairs;
        for (int r = 0; r < n; r++) {
            for (int l = 0; l < r; l++) {
                const int v = nums[l] * nums[r];
                ans += pairs[v] * 8;
                pairs[v]++;
            }
        }
        
        return ans;
    }
};
