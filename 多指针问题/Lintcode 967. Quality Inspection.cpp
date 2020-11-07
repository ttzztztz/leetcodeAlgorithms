class Solution {
public:
    /**
     * @param a: the excellent scores
     * @param b: the good scores
     * @param p: p% stands the line of valuable products.
     * @return: return the possible max number products to buy.
     */
    int qualityInspection(vector<int> &a, vector<int> &b, int p) {
        const int n = a.size();
        int ans = 0;
        typedef pair<int, int> PII;
        vector<PII> all;
        for (int i = 0; i < n; i++) all.emplace_back(a[i], i);
        for (int i = 0; i < n; i++) all.emplace_back(b[i], i);
        
        sort(all.begin(), all.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1.first < $2.first;
        });
        
        typedef long long ll;
        unordered_map<int, int> hmap;
        unordered_set<int> cur;
        for (int l = 0, r = 0; r < 2 * n; r++) {
            int val, idx;
            tie(val, idx) = all[r];
            
            cur.insert(idx);
            hmap[idx]++;
            
            const ll threshold = 1ll * p * val;
            while (l < r && 100ll * all[l].first < threshold) {
                const int l_idx = all[l].second;
                
                hmap[l_idx]--;
                if (hmap[l_idx] == 0) hmap.erase(l_idx);
                l++;
            }
            
            if (cur.size() == n) ans = max(ans, (int) hmap.size());
        }
        
        return ans;
    }
};
