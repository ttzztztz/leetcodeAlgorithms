class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--, n--;
        int ptr = nums1.size() - 1;
        while (m >= 0 && n >= 0) {
            if (nums1[m] <= nums2[n]) nums1[ptr] = nums2[n], n--;
            else nums1[ptr] = nums1[m], m--;

            ptr--;
        }

        while (m >= 0) {
            nums1[ptr] = nums1[m];
            m--, ptr--;
        }

        while (n >= 0) {
            nums1[ptr] = nums2[n];
            n--, ptr--;
        }
    }
};