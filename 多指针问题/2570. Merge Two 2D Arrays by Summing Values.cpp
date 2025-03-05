class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int ptr1 = 0, ptr2 = 0;
        const int len1 = nums1.size(), len2 = nums2.size();
        while (ptr1 < len1 && ptr2 < len2) {
            if (nums1[ptr1][0] == nums2[ptr2][0]) {
                ans.push_back(vector<int>{ nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1] });
                ptr1++, ptr2++;
            } else if (nums1[ptr1][0] < nums2[ptr2][0]) {
                ans.push_back(vector<int>{ nums1[ptr1][0], nums1[ptr1][1] });
                ptr1++;
            } else { // nums1[ptr1][0] > nums2[ptr2][0]
                ans.push_back(vector<int>{ nums2[ptr2][0], nums2[ptr2][1] });
                ptr2++;
            }
        }

        while (ptr1 < len1) {
            ans.push_back(nums1[ptr1]);
            ptr1++;
        }

        while (ptr2 < len2) {
            ans.push_back(nums2[ptr2]);
            ptr2++;
        }
        return ans;
    }
};