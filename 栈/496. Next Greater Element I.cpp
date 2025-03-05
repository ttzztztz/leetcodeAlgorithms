class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> res;
        vector<int> stk;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && nums2[stk.back()] < nums2[i]) stk.pop_back();
            if (!stk.empty()) res[nums2[i]] = nums2[stk.back()];
            stk.push_back(i);
        }

        vector<int> ans;
        for (int i : nums1) {
            if (res.count(i)) {
                ans.push_back(res[i]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};