class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int f[55];
        memset(f, 0, sizeof f);
        for (auto& range : ranges) {
            for (int i = range[0]; i <= range[1]; i++) f[i]++;
        }
        
        for (int i = left; i <= right; i++) {
            if (f[i] == 0) return false;
        }
        return true;
    }
};