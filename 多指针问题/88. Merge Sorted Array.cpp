class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto it = nums1.begin(), beginIt = nums1.begin();

        int ptr1 = m - 1, ptr2 = n - 1, pt = nums1.size() - 1;
        while (ptr1 >= 0 && ptr2 >= 0) {
            if (nums1[ptr1] < nums2[ptr2]) {
                nums1[pt] = nums2[ptr2];
                ptr2--;
                pt--;
            } else {
                nums1[pt] = nums1[ptr1];
                ptr1--;
                pt--;
            }
        }

        while (ptr2 >= 0) {
            nums1[pt] = nums2[ptr2];
            ptr2--;
            pt--;
        }
    }
};