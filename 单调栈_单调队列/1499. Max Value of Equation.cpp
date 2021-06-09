class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        const int n = points.size();
        int ans = numeric_limits<int>::min();
        
        deque<int> q;
        for (int j = 0; j < n; j++) {
            const int sum = points[j][0] + points[j][1];
            const int t = points[j][1] - points[j][0];
            
            while (!q.empty() && points[j][0] - points[q.front()][0] > k) q.pop_front();
            if (!q.empty()) ans = max(ans, sum + points[q.front()][1] - points[q.front()][0]);
            while (!q.empty() && points[q.back()][1] - points[q.back()][0] < t) q.pop_back();
            q.push_back(j);
        }
        
        return ans;
    }
};