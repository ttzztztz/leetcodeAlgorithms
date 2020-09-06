class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = pref[i][j - 1] + mat[i - 1][j - 1];
            }
        }
        int answer = 0;
        for (int a = 1; a <= m; a++) {
            for (int b = a; b <= m; b++) {
                vector<int> f;
                for (int i = 0; i < n; i++) {
                    if (pref[i + 1][b] - pref[i + 1][a - 1] == b - a + 1) {
                        f.push_back(i);
                    }
                }
                
                vector<int> cont;
                for (int i = 0; i < f.size(); i++) {
                    if (i == 0) cont.push_back(1);
                    else {
                        if (f[i - 1] + 1 == f[i]) {
                            (*cont.rbegin()) += 1;
                        } else {
                            cont.push_back(1);
                        }
                    }
                }
                
//                 for (int i : cont) cout << i << " ";
//                 cout << endl;
                
                for (int i : cont) answer += (i + 1) * i / 2;
            }
        }
        
        
        return answer;
    }
};
