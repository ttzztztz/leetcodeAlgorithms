class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        typedef long long ll;
        
        const int mod = 1e9+7;
        ll ans = 0;
        ll a = 0, b = 0;
        
        const int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                a += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                b += nums2[j++];
            } else {
                ans += max(a, b) + nums1[i];
                a = b = 0;
                i++, j++;
            }
        }
        
        while (i < n) a += nums1[i++];
        while (j < m) b += nums2[j++];
        return (ans + max(a, b)) % mod;
    }
};