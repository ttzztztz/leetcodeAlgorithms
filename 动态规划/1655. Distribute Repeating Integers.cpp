class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        this->q = quantity.size(), this->quantity = quantity;
        mask = (1 << q) - 1;
        
        unordered_map<int, int> app;
        for (int i : nums) app[i]++;
        for (auto& p : app) b.push_back(p.second);
        
        memset(f, 0xff, sizeof f);
        return dfs(0, 0);
    }
private:
    int q, mask;
    vector<int> b, quantity;
    int f[1050][55];
    
    int dfs(int state, int idx) {
        if (state == mask) return 1;
        if (idx == b.size()) return 0;
        
        int& val = f[state][idx];
        if (val != -1) return val;
        
        int answer = dfs(state, idx + 1);
        const int super = ((~state) & mask);
        for (int nxt = super; nxt; nxt = ((nxt - 1) & super)) {
            int sum = 0;
            for (int k = 0; k < q; k++) {
                if (nxt & (1 << k)) sum += quantity[k];
            }
            
            if (sum <= b[idx]) {
                answer |= dfs((state | nxt), idx + 1);
            }
        }
        return val = answer;
    }
};
