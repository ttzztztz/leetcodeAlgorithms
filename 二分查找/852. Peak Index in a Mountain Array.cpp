class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if (arr.empty()) return -1;

        const int n = arr.size();
        const int int_min = numeric_limits<int>::min();

        int l = 0, r = n - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;

            const int lval = mid - 1 >= 0 ? arr[mid - 1] : int_min;
            const int rval = mid + 1 < n ? arr[mid + 1] : int_min;
            const int val = arr[mid];

            if (lval <= val && val >= rval) return mid;

            if (lval <= val && val <= rval) l = mid + 1;
            else r = mid - 1; // lval >= val >= rval
        }

        return -1;
    }
};