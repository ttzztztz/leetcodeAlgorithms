class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        ans = init_ans = cur = vector<int>(2 * n - 1, -1);
        this->n = n;
        this->mask = (1 << n) - 1;
        dfs(0);
        return ans;
    }
private:
    vector<int> ans, init_ans;
    vector<int> cur;
    int n, mask;
    
    bool dfs(int state) {
        if (state == mask) {
            ans = cur;
            return true;
        }
        
        int idx = 0;
        while (idx < cur.size() && cur[idx] != -1) idx++;
        
        for (int i = n; i >= 1; i--) {
            if (state & (1 << (i - 1))) continue;
            
            if (i == 1) {
                cur[idx] = i;
                if (dfs(state | (1 << (i - 1)))) return true;
                cur[idx] = -1;
            } else if (i >= 2 && idx + i < cur.size() && cur[idx + i] == -1) {
                cur[idx] = cur[idx + i] = i;
                if (dfs(state | (1 << (i - 1)))) return true;
                cur[idx] = cur[idx + i] = -1;
            }
        }
        
        return false;
    }
};
