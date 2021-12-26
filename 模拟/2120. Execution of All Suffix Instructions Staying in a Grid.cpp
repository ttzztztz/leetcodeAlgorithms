class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        const int m = s.size();
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < n;
        };
        
        vector<int> ans(m, 0);
        for (int i = 0; i < m; i++) {
            int x = startPos[0], y = startPos[1], t = 0;
            for (int j = i; j < m; j++) {
                if (s[j] == 'L') y--;
                else if (s[j] == 'R') y++;
                else if (s[j] == 'U') x--;
                else if (s[j] == 'D') x++;
                
                if (!point_valid(x, y)) break;
                else t++;
            }
            ans[i] = t;
        }
        return ans;
    }
};
