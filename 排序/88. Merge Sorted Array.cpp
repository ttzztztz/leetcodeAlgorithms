class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int w = n + m - 1;
        int l = m - 1, r = n - 1;
        while (l >= 0 || r >= 0) {
            if (l >= 0 && r >= 0) {
                if (nums1[l] > nums2[r]) nums1[w] = nums1[l], l--, w--;
                else nums1[w] = nums2[r], r--, w--;
            } else if (l >= 0) {
                nums1[w] = nums1[l], l--, w--;
            } else if (r >= 0) {
                nums1[w] = nums2[r], r--, w--;
            }
        }
    }
};