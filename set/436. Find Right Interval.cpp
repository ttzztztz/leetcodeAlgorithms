class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<int> answer(n, -1);
        
        typedef pair<int, int> PII;
        set<PII> s;
        for (int i = 0; i < n; i++) {
            const auto& inter = intervals[i];
            const int l = inter[0];
            
            s.emplace(l, i);
        }
        
        for (int i = 0; i < n; i++) {
            const auto& inter = intervals[i];
            const int r = inter[1];
            
            auto it = s.lower_bound({r, -1});
            if (it != s.end()) answer[i] = it->second;
        }
        return answer;
    }
};
