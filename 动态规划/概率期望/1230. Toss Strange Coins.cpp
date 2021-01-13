class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        this->prob = prob;
        return dfs(0, target);
    }
private:
    unordered_map<int, double> f[1005];
    vector<double> prob;
    
    double dfs(int idx, int remain) {
        if (idx == prob.size()) {
            if (remain == 0) return 1.0;
            else return 0.0;
        }
        if (f[idx].count(remain)) return f[idx][remain];
        double& val = f[idx][remain];
        
        double ans = 0.0;
        if (remain >= 1) {
            ans += prob[idx] * dfs(idx + 1, remain - 1);
        }
        ans += (1.0 - prob[idx]) * dfs(idx + 1, remain);
        return val = ans;
    }
};
