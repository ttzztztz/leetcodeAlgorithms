// 三点共线的条件：下面的行列式计算结果为0
// | x1 x2 1 |
// | y1 y2 1 | = 0
// | z1 z2 1 |


class Solution {
public:
    int maxPoints(vector<vector<int>>& oldPoints) {
        if (oldPoints.size() <= 2) return oldPoints.size();
        
        map<vector<int>, int> appear;
        for (const auto& p : oldPoints) appear[p]++;
        
        vector<vector<int>> points;
        for (const auto& p : oldPoints) {
            if (appear[p] > 0) {
                points.push_back(vector<int>{p[0], p[1], appear[p]});
                appear[p] = 0;
            }
        }
        
        const int N = points.size();
        if (N <= 2) return oldPoints.size();
        
        auto cmp = [&](int i, int j, int k) -> bool {
            const long long x1 = points[i][0], y1 = points[j][0], z1 = points[k][0];
            const long long x2 = points[i][1], y2 = points[j][1], z2 = points[k][1];
            
            return (x1 * y2 - x2 * y1) + (y1 * z2 - y2 * z1) == -(x2 * z1 - x1 * z2);
        };
        
        int answer = 2;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int cur = points[i][2] + points[j][2];
                
                if (points[j][0] == points[i][0]) {
                    for (int k = 0; k < N; k++) {
                        if (i == k || j == k) continue;

                        if (points[k][0] == points[i][0]) cur += points[k][2];
                    }
                } else {

                    for (int k = 0; k < N; k++) {
                        if (i == k || j == k) continue;

                        if (cmp(i, j, k)) {
                            cur += points[k][2];
                        }
                    }
                }
                
                answer = max(answer, cur);
            }
        }
        return answer;
    }
};
