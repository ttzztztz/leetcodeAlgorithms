class Solution {
public:
    int missingElement(vector<int>& arr, int k) {
        const int n = arr.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;

            if (arr[mid] - mid - arr[0] < k) l = mid + 1;
            else r = mid - 1;
        }
        
        return arr[0] + r + k;
    }
};