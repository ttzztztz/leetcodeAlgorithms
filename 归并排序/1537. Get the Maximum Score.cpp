class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size(), M = nums2.size();
        long long a = 0, b = 0, answer = 0;
        const int mod = 1e9+7;
        
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < N && ptr2 < M) {
            if (nums1[ptr1] < nums2[ptr2]) {
                a += nums1[ptr1++];
            } else if (nums1[ptr1] > nums2[ptr2]) {
                b += nums2[ptr2++];
            } else {
                answer += max(a, b) + nums1[ptr1];
                a = 0, b = 0;
                ptr1++, ptr2++;
            }
        }
        while (ptr1 < N) {
            a += nums1[ptr1++];
        }
        while (ptr2 < M) {
            b += nums2[ptr2++];
        }
        
        answer += max(a, b);
        return answer % mod;
    }
};