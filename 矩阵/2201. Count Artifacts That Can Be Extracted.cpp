class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int ans = 0;
        vector<vector<int>> f(n, vector<int>(n, -1));
        vector<int> sze;
        for (int i = 0; i < artifacts.size(); i++) {
            int square = 0;
            for (int x = artifacts[i][0]; x <= artifacts[i][2]; x++) for (int y = artifacts[i][1]; y <= artifacts[i][3]; y++) {
                square++;
                f[x][y] = i;
            }
            sze.push_back(square);
        }
        
        for (auto& d : dig) {
            const int t = f[d[0]][d[1]];
            if (t != -1) {
                sze[t]--;
                if (sze[t] == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
