class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        
        sort(points.begin(), points.end(), [](const vector<int>& $1, const vector<int>& $2)->bool {
            if ($1[1] == $2[1]) {
                return $1[0] < $2[0];
            }
            return $1[1] < $2[1];
        });
        
        int answer = 1, current = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            const int start = points[i][0], end = points[i][1];
            
            if (start > current) {
                current = end;
                answer++;
            }
        }
        return answer;
    }
};
