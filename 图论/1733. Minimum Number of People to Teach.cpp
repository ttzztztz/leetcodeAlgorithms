class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        const int l = languages.size(), f = friendships.size();
        
        vector<unordered_set<int>> plang(l);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < languages[i].size(); j++) {
                plang[i].insert(languages[i][j]);
            }
        }
        
        unordered_set<int> not_avail;
        
        auto ok = [&](int u, int v) -> bool {
            for (int la : plang[u]) {
                if (plang[v].count(la)) return true;
            }
            return false;
        };
        
        for (auto& fr : friendships) {
            const int u = fr[0] - 1, v = fr[1] - 1;
            if (!ok(u, v)) {
                not_avail.insert(u);
                not_avail.insert(v);
            }
        }
        
        int ans = -1;
        for (int i = 1; i <= 500; i++) {
            int cur = 0;
            for (int u : not_avail) {
                if (!plang[u].count(i)) cur++;
            }
            
            if (ans == -1 || cur < ans) ans = cur;
        }
        return ans;
    }
};
