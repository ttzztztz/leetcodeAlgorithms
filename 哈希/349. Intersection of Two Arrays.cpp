class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        auto it1 = unique(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it2 = unique(nums2.begin(), nums2.end());
        
        unordered_map<int, int> app;
        for (auto it = nums1.begin(); it != it1; it++) app[*it]++;
        for (auto it = nums2.begin(); it != it2; it++) app[*it]++;
        vector<int> answer;
        for (auto& p : app) {
            if (p.second == 2) answer.push_back(p.first);
        }
        return answer;
    }
};