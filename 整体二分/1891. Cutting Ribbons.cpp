class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        if (ribbons.empty()) return -1;
        int l = 1, r = *max_element(ribbons.begin(), ribbons.end());
        while (l <= r) {
            const int mid = (l + r) / 2;
            
            if (calc_slices(ribbons, mid) < k) r = mid - 1;
            else l = mid + 1;
        }
        return r;
    }
private:
    int calc_slices(const vector<int>& ribbons, int size) {
        int ans = 0;
        for (int i : ribbons) ans += i / size;
        return ans;
    }
};