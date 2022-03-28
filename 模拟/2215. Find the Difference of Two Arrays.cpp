class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        
        unordered_set<int> f1(nums1.begin(), nums1.end());
        unordered_set<int> f2(nums2.begin(), nums2.end());
        
        for (auto& v1 : f1) {
            if (!f2.count(v1)) ans[0].push_back(v1);
        }
        for (auto& v2 : f2) {
            if (!f1.count(v2)) ans[1].push_back(v2);
        }
        
        return ans;
    }
};
