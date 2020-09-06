class Solution {
public:
    int numPoints(vector<vector<int>>& old, int r) {
        vector<VD> points;
        for (const auto& v : old) points.push_back(VD{(double) v[0], (double) v[1]});
        this->r = r;
        int answer = 1;
        
        const int N = points.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist(points[i], points[j]) > EPS + 4 * r * r) continue;
                
                VD o1 = getCircle(points[i], points[j]);
                answer = max(answer, check(o1, points));
            }
        }
        
        return answer;
    }
private:
    typedef long long LL;
    typedef vector<double> VD;
    double r;
    const double EPS = 1e-7;
    VD getCircle(const VD& $1, const VD& $2) {
        VD answer = {0.0, 0.0};
        
        const double m = sqrt(dist($1, $2)) / 2.0;
        const double d = sqrt(r * r - m * m);
        const double ang = atan2($1[1] - $2[1], $1[0] - $2[0]);
        
        answer[0] = ($1[0] + $2[0]) / 2.0 + d * sin(ang);
        answer[1] = ($1[1] + $2[1]) / 2.0 - d * cos(ang);
        
        return answer;
    }
    int check(VD& circle, vector<VD>& points) {
        int answer = 0;
        for (int i = 0; i < points.size(); i++) {
            if (dist(points[i], circle) <= r * r + EPS) answer++;
        }
        return answer;
    }
    double dist(const VD& $1, const VD& $2) {
        return (1.0 * ($1[0] - $2[0]) * ($1[0] - $2[0])) + (1.0 * ($1[1] - $2[1]) * ($1[1] - $2[1]));
    }
};
