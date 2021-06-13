class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& arr, vector<int>& target) {
        sort(arr.begin(), arr.end());
        const int n = arr.size();
        
        vector<int> last = { 0, 0, 0 };
        for (int i = 0; i < n; i++) {
            const auto& cur = arr[i];
            if (
                max(last[0], cur[0]) <= target[0] && 
                max(last[1], cur[1]) <= target[1] && 
                max(last[2], cur[2]) <= target[2]
            ) {
                last[0] = max(last[0], cur[0]);
                last[1] = max(last[1], cur[1]);
                last[2] = max(last[2], cur[2]);
            }
            
            if (last == target) return true;
        }
        return false;
    }
};