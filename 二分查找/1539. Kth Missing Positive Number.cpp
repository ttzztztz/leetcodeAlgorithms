class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const int num = arr[mid] - mid - 1;
            
            if (num < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return k + l;
    }
};
