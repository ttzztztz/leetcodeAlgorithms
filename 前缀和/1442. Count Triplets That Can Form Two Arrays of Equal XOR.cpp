class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int n = arr.size();
        
        int ans = 0, sum = 0;
        for (int k = 1; k <= n; k++) {
            sum ^= arr[k - 1]; // f[k]
            
            int t = 0;
            for (int d = 0; d <= k; d++) { // f[i - 1], d = i - 1
                if (d >= 1) t ^= arr[d - 1];
                
                if (t == sum) ans += max(0, k - d - 1);
            }
            
        }
        return ans;
    }
};