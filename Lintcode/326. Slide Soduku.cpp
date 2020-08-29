class Solution {
public:
    /**
     * @param number: an only contains from 1 to 9 array
     * @return: return  whether or not each sliding window position contains all the numbers for 1 to 9 
     */
    vector<bool> SlidingWindows(vector<vector<int>> &number) {
        const int n = number[0].size();
        vector<bool> answer(n - 2, false);
        
        int v[10];
        memset(v, 0, sizeof v);
        int cnt = 0;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                v[number[i][j]]++;
                if (v[number[i][j]] == 1) cnt++;
            }
        }
        
        if (cnt == 9) answer[0] = true;
        for (int k = 1, l = 0, r = 3; r < n; k++, l++, r++) {
            for (int x = 0; x < 3; x++) {
                v[number[x][l]]--;
                if (v[number[x][l]] == 0) cnt--;
            }
            for (int x = 0; x < 3; x++) {
                v[number[x][r]]++;
                if (v[number[x][r]] == 1) cnt++;
            }
            
            if (cnt == 9) answer[k] = true;
        }
        
        return answer;
    }
};
