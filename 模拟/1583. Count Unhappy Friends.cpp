class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int answer = 0;
        unordered_map<int, int> p;
        for (auto& v : pairs) p[v[0]] = v[1], p[v[1]] = v[0];

        vector<unordered_map<int, int>> pref(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                pref[i][preferences[i][j]] = n - j;
            }
        }
        
        for (int x = 0; x < n; x++) {
            const int y = p[x];
            for (int u : preferences[x]) {
                if (u == y) break;
                const int v = p[u];
                
                if (pref[u][x] > pref[u][v]) {
                    answer++;
                    break;
                }
            }
        }
        
        return answer;
    }
};
