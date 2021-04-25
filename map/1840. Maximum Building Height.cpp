class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(), restrictions.end(), [&](auto& lhs, auto& rhs) -> bool {
            return lhs[1] < rhs[1];
        });
        
        map<int, int> h; // id -> height
        h[1] = 0;
        for (auto& restriction : restrictions) {
            int id = restriction[0], mh = restriction[1];
            
            auto l = h.lower_bound(id);
            if (l != h.begin()) {
                l--;
                if (l != h.end()) {
                    auto [lid, lh] = *l;
                    mh = min(mh, lh + (id - lid));
                }
            }
            auto r = h.upper_bound(id);
            if (r != h.end()) {
                auto [rid, rh] = *r;
                mh = min(mh, rh + (rid - id));
            }
            
            h[id] = mh;
        }
        
        int ans = 0;
        auto [eid, eh] = *h.rbegin();
        ans = eh + (n - eid);
        
        for (auto lit = h.begin(), rit = ++h.begin(); rit != h.end(); lit++, rit++) {
            auto [lid, lh] = *lit;
            auto [rid, rh] = *rit;

            const int delta = max(lh, rh) - min(lh, rh);
            const int dist = rid - lid - 1;
            int cur = max(lh, rh);
            cur += max(0, (dist - delta + 1) / 2);
            ans = max(ans, cur);
        }
        
        return ans;
    }
};