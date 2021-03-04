class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        const int n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (!s.count(i)) return i;
        }
        return -1;
    }
};
