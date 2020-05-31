class Solution {
public:
    double getProbability(vector<int>& balls) {
        fracf = {0.0, 0.0};
        for (int i = 2; i <= 48; i++) {
            fracf.push_back(fracf[i - 1] + log2((double) i));
        }
        
        int total = 0;
        for (int i : balls) total += i;
        
        G = balls.size();
        vector<int> pick(G, 0);
        
        const double ok = dfs(balls, pick, total / 2, 0);
        const double all = pow(2.0, Cf(total, total / 2));
        
        return ok / all;
    }
private:
    vector<double> fracf;
    int G;
    double Cf(int n, int m) {
        return fracf[n] - fracf[m] - fracf[n - m];
    }
    bool valid(const vector<int>& pick, const vector<int>& balls) {
        int left = 0, right = 0;
        for (int i = 0; i < G; i++) {
            if (pick[i] == 0) {
                right++;
            } else if (pick[i] == balls[i]) {
                left++;
            } else {
                left++, right++;
            }
        }
        return left == right;
    }
    double dfs(const vector<int>& balls, vector<int>& pick, int pickCnt, int index) {
        if (pickCnt < 0) return 0.0;
        if (index == G) {
            if (!valid(pick, balls) || pickCnt != 0) return 0.0;
            
            double answer = 0.0;
            for (int i = 0; i < G; i++) {
                answer += Cf(balls[i], pick[i]);
            }
            return pow(2.0, answer);
        }
        
        double answer = 0.0;
        for (int i = 0; i <= balls[index]; i++) {
            pick[index] = i;
            answer += dfs(balls, pick, pickCnt - i, index + 1);
        }
        return answer;
    }
};
