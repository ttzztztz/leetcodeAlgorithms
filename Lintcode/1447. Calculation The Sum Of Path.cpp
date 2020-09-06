/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    vector<long long> multiply;
    int MOD;
    long long calculationTheSumOfPath(int N, int M, vector<Point> &points) {
        MOD = 1e9+7;
        
        multiply.push_back(1);
        for (int i = 1; i <= (N + M); i++) {
            long long nxt = multiply[i - 1] * i;
            nxt %= MOD;
            multiply.push_back(nxt);
        }
        
        vector<pair<int, int>> point;
        for (const Point& p : points) point.emplace_back(p.x, p.y);
        sort(point.begin(), point.end(), [](const auto& $1, const auto& $2)->bool {
            if ($1.first == $2.first) return $1.second < $2.second;
            else return $1.first < $2.first;
        });
        
        long long answer = 1;
        int curX = 1, curY = 1;
        for (int i = 0; i < 3; i++) {
            answer *= solve(curX, curY, point[i].first, point[i].second);
            answer %= MOD;
            
            curX = point[i].first;
            curY = point[i].second;
        }
        
        answer *= solve(curX, curY, N, M);
        answer %= MOD;
        return answer;
    }
    long long solve(int startX, int startY, int endX, int endY) {
        const int N = endX - startX;
        const int M = endY - startY;
        
        long long answer = multiply[N + M];
        answer %= MOD;
        
        answer *= fastPow(multiply[N], MOD - 2);
        answer %= MOD;
        
        answer *= fastPow(multiply[M], MOD - 2);
        answer %= MOD;
        return answer;
    }
    long long fastPow(int a, int b) {
        long long answer = 1, base = a;
        while (b) {
            if (b & 1) {
                answer *= base;
                answer %= MOD;
            }
            
            base *= base;
            base %= MOD;
            b >>= 1;
        }
        return answer;
    }
};
