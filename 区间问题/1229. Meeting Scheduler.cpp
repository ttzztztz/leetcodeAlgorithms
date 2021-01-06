class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        for (int i = 0, j = 0; i < slots1.size() && j < slots2.size();) {
            const int l = max(slots1[i][0], slots2[j][0]), r = min(slots1[i][1], slots2[j][1]);
            if (l <= r && l + duration <= r) {
                return { l, l + duration };
            }
            
            if (slots1[i][1] < slots2[j][1]) i++;
            else j++;
        }
        return {};
    }
};
