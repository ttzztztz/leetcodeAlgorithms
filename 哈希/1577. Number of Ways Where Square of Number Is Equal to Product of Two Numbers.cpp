class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        typedef long long ll;
        
        unordered_map<ll, int> a, b;
        for (int i : nums1) a[i]++;
        for (int i : nums2) b[i]++;
        
        const int n = nums1.size(), m = nums2.size();
        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            const ll t = 1ll * nums1[i] * nums1[j];
            const ll v = sqrt(t);
            if (v * v == t) ans += b[v];
        }
        
        for (int i = 0; i < m; i++) for (int j = i + 1; j < m; j++) {
            const ll t = 1ll * nums2[i] * nums2[j];
            const ll v = sqrt(t);
            if (v * v == t) ans += a[v];
        }
        return ans;
    }
};

// class Solution {
// public:
//     int numTriplets(vector<int>& nums1, vector<int>& nums2) {
//         typedef long long ll;
        
//         unordered_map<ll, int> a, b;
//         for (int i : nums1) a[1ll * i * i]++;
//         for (int i : nums2) b[1ll * i * i]++;
        
//         const int n = nums1.size(), m = nums2.size();
//         int ans = 0;
//         for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
//             const ll t = 1ll * nums1[i] * nums1[j];
//             ans += b[t];
//         }
        
//         for (int i = 0; i < m; i++) for (int j = i + 1; j < m; j++) {
//             const ll t = 1ll * nums2[i] * nums2[j];
//             ans += a[t];
//         }
//         return ans;
//     }
// };