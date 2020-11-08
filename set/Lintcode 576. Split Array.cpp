class Solution {
public:
    /**
     * @param arr: an inter array 
     * @return: return the min sum
     */
    int splitArray(vector<int> &arr) {
        const int n = arr.size();
        int ans = numeric_limits<int>::max();
        
        set<int> f;
        for (int i = 0; i < n - 1; i++) {
            if (i - 2 > 0) f.insert(arr[i - 2]);
            
            if (!f.empty()) ans = min(ans, arr[i] + *f.begin());
        }
        return ans;
    }
};
