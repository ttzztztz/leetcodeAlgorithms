class Solution {
public:
    int app[21][100005];
    int closestToTarget(vector<int>& arr, int target) {
        int answer = abs(-1000000000 - target);
        const int N = arr.size();
        
        memset(app, sizeof app, 0);
        for (int i = 1; i <= N; i++) {
            const int num = arr[i - 1];
            for (int j = 0; j < 21; j++) {
                if (num & (1 << j)) app[j][i] = app[j][i - 1] + 1;
                else app[j][i] = app[j][i - 1];
            }
        }
        
        auto f = [&](int i, int j) -> int {
            int answer = 0;
            for (int k = 0; k < 21; k++) {
                if (app[k][j] - app[k][i - 1] == j - i + 1) answer |= (1 << k);
            }
            return answer;
        };
        
        for (int r = 1; r <= N; r++) {
            int left = 1, right = r;
            while (left <= right) {
                const int mid = (left + right) >> 1;
                
                const int x = f(mid, r);
                
                if (x < target) left = mid + 1;
                else if (x > target) right = mid - 1;
                else return 0;
            }
            
            if (left <= r) answer = min(answer, abs(f(left, r) - target));
            if (right >= 1) answer = min(answer, abs(f(right, r) - target));
        }
        
        return answer;
    }
};
