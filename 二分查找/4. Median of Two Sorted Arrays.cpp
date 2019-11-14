class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        const int N = nums1.size(), M = nums2.size(), K = (N + M + 1) >> 1;

        int left = 0, right = N - 1;
        while (left <= right) {
            const int middle1 = (left + right) >> 1;
            const int middle2 = K - middle1;
            if (nums1[middle1] <= nums2[middle2 - 1]) {
                left = middle1 + 1;
            } else {
                right = middle1 - 1;
            }
        }

        const int middle1 = left;
        const int middle2 = K - middle1;

        const int center1 = max(
                middle1 <= 0 ? -999999 : nums1[middle1 - 1],
                middle2 <= 0 ? -999999 : nums2[middle2 - 1]
        );

        const int center2 = min(
                middle1 >= N ? 999999 : nums1[middle1],
                middle2 >= M ? 999999 : nums2[middle2]
        );

        if ((N + M) % 2 == 1) { // odd
            return center1;
        } else {
            return 0.5 * (center1 + center2);
        }

    }
};