class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        const int n = arr.size();
        
        const int median_idx = (n - 1) / 2;
        nth_element(arr.begin(), arr.begin() + median_idx, arr.end());
        const int median = arr[median_idx];
        
        nth_element(arr.begin(), arr.begin() + k, arr.end(), [&](int i, int j) -> bool {
            if (abs(i - median) == abs(j - median)) {
                return i > j;
            }
            return abs(i - median) > abs(j - median);
        });
        
        vector<int> ans(k);
        for (int i = 0; i < k; i++) ans[i] = arr[i];
        return ans;
    }
};