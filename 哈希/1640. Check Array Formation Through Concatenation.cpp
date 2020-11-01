
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        const int n = arr.size(), m = pieces.size();
        vector<bool> used(m + 1, false);
        
        for (int ptr = 0; ptr < n; ) {
            bool ok = false;
            for (int j = 0; j < m; j++) {
                if (used[j]) continue;
                
                const int t = pieces[j].size();
                bool can = true;
                for (int k = 0; k < t; k++) {
                    if (arr[ptr + k] != pieces[j][k]) {
                        can = false;
                        break;
                    }
                }
                
                if (can) {
                    used[j] = true;
                    ptr += t;
                    ok = true;
                    break;
                }
            }
            
            if (!ok) return false;
        }
        
        return true;
    }
};
