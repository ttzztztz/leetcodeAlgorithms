class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> difference(1005, 0);
        for (const vector<int>& trip : trips) {
            difference[trip[1]] += trip[0];
            difference[trip[2]] -= trip[0];
        }
        
        for (int i = 1; i <= 1000; i++) {
            difference[i] += difference[i - 1];
            if (difference[i] > capacity) return false;
        }
        
        return true;
    }
};
