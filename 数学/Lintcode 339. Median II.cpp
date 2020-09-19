class Solution {
public:
    /**
     * @param arr: an integer array
     * @return: return the median array when delete a number
     */
    vector<int> getMedian(vector<int> &arr) {
        const int n = arr.size();
        vector<int> s = arr;
        vector<int> ans(n, 0);
        sort(s.begin(), s.end());
        const double mid = 0.5 * (s[n / 2] + s[(n / 2) - 1]);
        
        for (int i = 0; i < n; i++) {
            const double t = arr[i];
            
            if (t < mid) ans[i] = s[n / 2];
            else ans[i] = s[(n / 2) - 1];
        }
        
        return ans;
    }
};
