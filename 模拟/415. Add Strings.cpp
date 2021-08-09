class Solution {
public:
    string addStrings(string nums1, string nums2) {
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        
        const int n = nums1.size(), m = nums2.size();
        string ans(max(n, m) + 1, '0');
        for (int i = 0, carry = 0; i <= max(n, m); i++) {
            ans[i] = carry + (i < n ? (nums1[i] - '0') : 0) + (i < m ? (nums2[i] - '0') : 0);
            if (ans[i] >= 10) {
                carry = 1;
                ans[i] -= 10;
            } else {
                carry = 0;
            }
            
            ans[i] += '0';
        }
        
        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};