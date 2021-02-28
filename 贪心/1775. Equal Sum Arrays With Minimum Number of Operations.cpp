class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        const int l1 = n, u1 = 6 * n, l2 = m, u2 = 6 * m;
        if (max(l1, l2) <= min(u1, u2)) {
            int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
            int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
            
            if (sum1 == sum2) return 0;
            if (sum1 > sum2) {
                swap(sum1, sum2);
                swap(nums1, nums2);
            }
            
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            
            int ptr1 = 0, ptr2 = nums2.size() - 1;
            int ans = 0;
            while (sum1 < sum2) {
                if (ptr1 >= nums1.size()) {
                    ans += ptr2 + 1;
                    break;
                }
                if (ptr2 < 0) {
                    ans += nums2.size() - ptr1;
                    break;
                }
                int a = nums1[ptr1];
                int b = nums2[ptr2];
                
                if (6 - a >= b - 1) {
                    ptr1++;
                    sum1 += 6 - a;
                } else {
                    ptr2--;
                    sum1 += b - 1;
                }
                ans++;
            }
            return ans;
        } else {
            return -1;
        }
    }
};
