class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        if (box.empty()) return {};
        const int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            ans[j][i] = box[i][j];
        }
        for (int i = 0; i < m; i++) reverse(ans[i].begin(), ans[i].end());
        
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
        for (int j = 0; j < n; j++) {
            int last = m;
            for (int i = m - 1; i >= 0; i--) {
                if (ans[i][j] == '*') {
                    last = i;
                } else if (ans[i][j] == '#') {
                    last--;
                    ans[last][j] = '#';
                    if (last != i) ans[i][j] = '.';
                }
            }
        }
        return ans;
    }
};