class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        const int n = rooms.size(), q = queries.size();
        vector<int> ans(q, -1);
        for (int i = 0; i < q; i++) queries[i].push_back(i);
        
        // memset(data, 0, sizeof data);
        sort(rooms.begin(), rooms.end(), [](const auto& lhs, const auto& rhs) -> bool {
            return lhs[1] < rhs[1];
        });
        sort(queries.begin(), queries.end(), [](const auto& lhs, const auto& rhs) -> bool {
            return lhs[1] < rhs[1];
        });
        
        for (int i = 0; i < n; i++) {
            t.insert(rooms[i][0]);
        }
        
        for (int i = 0, ptr = 0; i < q; i++) {
            const int p = queries[i][0], ms = queries[i][1], idx = queries[i][2];
            while (ptr < n && rooms[ptr][1] < ms) {
                t.erase(rooms[ptr][0]);
                ptr++;
            }
            
            int& val = ans[idx];
            if (t.empty()) continue;
            
            auto itr = t.lower_bound(p);
            if (itr != t.end() && *itr == p) {
                val = *itr;
                continue;
            }
            
            if (itr != t.begin()) {
                auto itl = itr;
                itl--;
                val = *itl;
            }
            
            if (itr != t.end()) {
                const int cur = *itr;
                if (val == -1 || abs(val - p) > abs(cur - p)) {
                    val = cur;
                }
            }
        }
        return ans;
    }
private:
    set<int> t;
};