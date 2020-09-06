class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int answer = numeric_limits<int>::min();
        
        deque<int> q;
        for (int i = 0; i < points.size(); i++) {
            const int t = points[i][0] + points[i][1];
            const int c = points[i][1] - points[i][0];
            
            while (!q.empty() && points[i][0] - points[q.front()][0] > k) q.pop_front();
            if (!q.empty()) answer = max(answer, t + points[q.front()][1] - points[q.front()][0]);
            while (!q.empty() && points[q.back()][1] - points[q.back()][0] <= c) q.pop_back();
            
            q.push_back(i);
        }
        
        return answer;
    }
};