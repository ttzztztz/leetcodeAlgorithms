class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] == 2) {
                colsum[i] = 0;
                ans[0][i] = ans[1][i] = 1;
                upper -= 1;
                lower -= 1;
                
                if (upper < 0 || lower < 0) return {};
            }
        }
        
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] == 1) {
                if (upper > 0) {
                    upper--;
                    colsum[i] = 0;
                    ans[0][i] = 1;
                } else if (lower > 0) {
                    lower--;
                    colsum[i] = 0;
                    ans[1][i] = 1;
                } else {
                    return {};
                }
            }
        }
        
        if (upper > 0 || lower > 0) return {};
        else return ans;
    }
};