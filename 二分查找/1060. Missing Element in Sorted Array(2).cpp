class Solution {
public:
    int missingElement(vector<int>& arr, int i) {
        int l = arr.front(), r = arr.back() + i;
        // SC: O(1)
        // TC: O(log^2n)
        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const int res = f(arr, mid);
            if (res >= i) r = mid - 1;
            else l = mid + 1;
        }
        
        return l;
    }
private:
    int f(const vector<int>& arr, int x) {
        const int i = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        return x - arr[0] - i;
    }
};
