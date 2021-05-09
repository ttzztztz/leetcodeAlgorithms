class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            j = max(j, i);
            while (i <= j && j < m && nums1[i] <= nums2[j]) {
                ans = max(ans, abs(i - j));
                j++;
            }
        }
        return ans;
    }
};
