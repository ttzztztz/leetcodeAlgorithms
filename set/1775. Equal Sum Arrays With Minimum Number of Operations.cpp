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
            
            multiset<int> s1(nums1.begin(), nums1.end());
            multiset<int> s2(nums2.begin(), nums2.end());
            
            int ans = 0;
            while (sum1 < sum2) {
                if (s1.empty()) {
                    ans += s2.size();
                    break;
                }
                if (s2.empty()) {
                    ans += s1.size();
                    break;
                }
                int a = *s1.begin();
                int b = *s2.rbegin();
                
                if (6 - a >= b - 1) {
                    s1.erase(s1.begin());
                    sum1 += 6 - a;
                } else {
                    s2.erase(--s2.end());
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
