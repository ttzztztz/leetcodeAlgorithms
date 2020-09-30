class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<int> v = {-1, -1};
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto& $1, const auto& $2) -> bool {
            if ($1[1] == $2[1]) return $1[0] > $2[0];
            return $1[1] < $2[1];
        });
        
        for (int i = 0; i < n; i++) {
            const int l = intervals[i][0], r = intervals[i][1];
            
            if (l <= v[v.size() - 2]) continue;
            else if (l > v.back()) v.push_back(r - 1);
            v.push_back(r);
        }
        
        return v.size() - 2;
    }
};
