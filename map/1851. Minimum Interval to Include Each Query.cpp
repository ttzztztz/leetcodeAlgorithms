class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& qr) {
        const int n = intervals.size(), q = qr.size();
        vector<vector<int>> queries;
        for (int i = 0; i < q; i++) queries.push_back(vector<int>{ qr[i], i });
        
        sort(queries.begin(), queries.end());
        sort(intervals.begin(), intervals.end());
        
        vector<int> ans(q, -1);
        map<int, int> sizes;
        map<int, vector<int>> right;
        for (int i = 0, ptr = 0; i < q; i++) {
            const int mid = queries[i][0], idx = queries[i][1];
            int& val = ans[idx];
            while (ptr < n && intervals[ptr][0] <= mid) {
                const int len = intervals[ptr][1] - intervals[ptr][0] + 1;
                right[intervals[ptr][1]].push_back(len);
                sizes[len]++;
                ptr++;
            }
            
            while (!right.empty() && right.begin()->first < mid) {
                for (auto& sze : right.begin()->second) {
                    sizes[sze]--;
                    if (sizes[sze] == 0) sizes.erase(sze);
                }
                right.erase(right.begin());
            }
            if (!sizes.empty()) val = sizes.begin()->first;
        }
        return ans;
    }
};