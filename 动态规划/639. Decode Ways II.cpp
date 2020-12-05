class Solution {
public:
    int numDecodings(string s) {
        memset(f_, 0xff, sizeof f_);
        this->s_ = s, this->n_ = s.size();
        
        return Dfs(0, 10);
    }
private:
    int f_[100005][11];
    string s_;
    int n_;
    const int kMod = 1e9+7;
    
    int Dfs(int idx, int last) {
        if (idx == n_) return (last == 10) ? 1 : 0;
        int& val = f_[idx][last];
        if (val != -1) return val;
        
        int ans = 0;
        if (s_[idx] == '*') {
            for (int k = 1; k <= 9; k++) {
                if (last == 10) {
                    ans = (ans + Dfs(idx + 1, k) + Dfs(idx + 1, 10)) % kMod;
                } else {
                    const int t = last * 10 + k;
                    if (t >= 1 && t <= 26) {
                        ans = (ans + Dfs(idx + 1, 10)) % kMod;
                    }
                }
            }
            
            return val = ans;
        } else if (s_[idx] == '0' && last == 10) {
            return val = 0;
        }
        
        if (last == 10) {
            ans = (ans + Dfs(idx + 1, s_[idx] - '0') + Dfs(idx + 1, 10)) % kMod;
        } else {
            const int t = last * 10 + (s_[idx] - '0');
            if (t >= 1 && t <= 26) {
                ans = (ans + Dfs(idx + 1, 10)) % kMod;
            }
        }
        
        return val = ans;
    }
};
