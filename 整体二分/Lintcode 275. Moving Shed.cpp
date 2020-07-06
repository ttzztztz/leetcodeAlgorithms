class Solution {
public:
    /**
     * @param stops: An array represents where each car stops.
     * @param k: The number of cars should be covered.
     * @return: return the minimum length of the shed that meets the requirements.
     */
    int calculate(vector<int> &stops, int k) {
        // write your code here
        const int N = stops.size();
        sort(stops.begin(), stops.end());
        
        int left = 1, right = stops[N - 1] - stops[0];
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            if (solve(stops, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    bool solve(const vector<int>& v, int k, int len) {
        int ptr1 = 0, ptr2 = 0;
        for (int l = v[0], r = l + len - 1; r <= v[v.size() - 1]; l++, r++) {
            while (v[ptr1] < l) ptr1++;
            while (v[ptr2] <= r) ptr2++;
            const int cover = ptr2 - ptr1;
            
            if (cover < k) return false;
        }
        return true;
    }
};
