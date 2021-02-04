class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return solve(nums2, nums1);
        else return solve(nums1, nums2);
    }
private:
    int n, m;
    
    double solve(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(), m = nums2.size();

        nums1.push_back(numeric_limits<int>::max());
        nums2.push_back(numeric_limits<int>::max());
        nums1.insert(nums1.begin(), numeric_limits<int>::min());
        nums2.insert(nums2.begin(), numeric_limits<int>::min());

        if ((n + m) % 2 == 1) { // odd
            return 1.0 * binary_search(nums1, nums2, (n + m + 1) / 2);
        } else {
            const int a = binary_search(nums1, nums2, (n + m) / 2);
            const int b = binary_search(nums1, nums2, (n + m) / 2 + 1);

            return 0.5 * (a + b);
        }
    }

    int binary_search(vector<int>& nums1, vector<int>& nums2, int d) {
        int l = 0, r = n;
        
        while (l <= r) {
            const int mid = (l + r) / 2;
            const int i = mid;
            const int j = d - i;

            if (nums1[i] < nums2[j]) {
                l = mid + 1;
            } else if (nums1[i] > nums2[j]) {
                r = mid - 1;
            } else { // equal
                return nums1[i];
            }
        }
        
        if (0 <= l && l <= n && max(nums1[l], nums2[d - l]) <= min(nums1[l + 1], nums2[d - l + 1])) {
            return max(nums1[l], nums2[d - l]);
        } else {
            return max(nums1[r], nums2[d - r]);
        }
    }
};
