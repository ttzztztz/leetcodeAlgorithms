class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> pointSet;
        for (const vector<int>& point : points) {
            pointSet.emplace(point[0], point[1]);
        }

        int answer = 99999999;
        const int N = points.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                const int x1 = points[i][0], y1 = points[i][1], x4 = points[j][0], y4 = points[j][1];

                const int x2 = x1, y2 = y4, x3 = x4, y3 = y1;
                if (pointSet.count({x2, y2}) && pointSet.count({x3, y3})) {
                    const int temp = abs(x1 - x4) * abs(y1 - y4);
                    if (temp != 0) {
                        answer = min(answer, temp);
                    }
                }
            }
        }
        return answer == 99999999 ? 0 : answer;
    }
};