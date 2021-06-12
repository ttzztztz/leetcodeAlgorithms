class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        const int n = arr.size();
        int ans = numeric_limits<int>::max();
        
        vector<int> pref(21, 0);
        for (int l = 0, r = 0; r < n; r++) {
            for (int i = 0; i < 21; i++) {
                pref[i] += (arr[r] & (1 << i)) ? 1 : 0;
            }
            
            while (generate(l, r, pref) <= target) {
                ans = min(ans, abs(target - generate(l, r, pref)));
                for (int i = 0; i < 21; i++) {
                    pref[i] -= (arr[l] & (1 << i)) ? 1 : 0;
                }
                l++;
            }
            ans = min(ans, abs(target - generate(l, r, pref)));
        }
        return ans;
    }
private:
    int generate(int l, int r, const vector<int>& pref) {
        int ans = 0;
        for (int i = 0; i < 21; i++) {
            if ((r - l + 1) == pref[i]) ans |= (1 << i);
        }
        return ans;
    }
};