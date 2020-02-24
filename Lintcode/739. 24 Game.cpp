class Solution {
public:
    /**
     * @param nums: 4 cards
     * @return: whether they could get the value of 24
     */
    bool compute24(vector<double> &nums) {
        return dfs(nums);
    }
    bool dfs(const vector<double>& cur) {
        if (cur.size() == 0) return false;
        if (cur.size() == 1) return abs(cur[0] - 24.0) <= 1e-6;
        
        const int N = cur.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                
                vector<double> nxt;
                for (int k = 0; k < N; k++) {
                    if (k == i || k == j) continue;
                    nxt.push_back(cur[k]);
                }
                
                nxt.push_back(cur[i] + cur[j]);
                if (dfs(nxt)) return true;
                nxt.pop_back();
                
                nxt.push_back(cur[i] - cur[j]);
                if (dfs(nxt)) return true;
                nxt.pop_back();
                
                nxt.push_back(cur[i] * cur[j]);
                if (dfs(nxt)) return true;
                nxt.pop_back();
                
                nxt.push_back(cur[i] / cur[j]);
                if (dfs(nxt)) return true;
                nxt.pop_back();
            }
        }
        return false;
    }
};
