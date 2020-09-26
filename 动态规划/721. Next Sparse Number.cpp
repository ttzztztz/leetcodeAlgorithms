class Solution {
public:
    /**
     * @param x: a number
     * @return: return the next sparse number behind x
     */
    int nextSparseNum(int x) {
        if (x == 0) return 0;
        
        memset(f, 0xff, sizeof f);
        memset(g, 0xff, sizeof f);
        memset(digits, 0, sizeof digits);
        init(x);
        
        int ans = 1 << digitLen;
        bool ok;
        int _ans;
        tie(ok, _ans) = dfs(digitLen - 1, 1, 0);
        if (ok) {
            ans = min(ans, _ans | (1 << (digitLen - 1)));
        }
        return ans;
    }
private:
    int f[35][2][2], g[35][2][2];
    int digits[35];
    int digitLen = 0;
    
    void init(int x) {
        while (x) {
            digits[++digitLen] = x & 1;
            x >>= 1;
        }
    }
    
    pair<bool, int> dfs(int d, int last, int bigger) {
        if (d == 0) return make_pair(true, 0);

        int& valf = f[d][last][bigger];
        int& valg = g[d][last][bigger];

        if (valg != -1) {
            return make_pair(valg, valf);
        }
        
        bool find = false;
        int ans = numeric_limits<int>::max();
        
        // fill 0
        if (bigger || digits[d] == 0) {
            bool _res;
            int _ans = 0;
            
            tie(_res, _ans) = dfs(d - 1, 0, bigger);
            if (_res) {
                find = true;
                ans = min(ans, _ans);
            }
        }
        
        // fill 1
        if (last == 0) {
            bool _res;
            int _ans = 0;
            
            tie(_res, _ans) = dfs(d - 1, 1, bigger || digits[d] == 0);
            if (_res) {
                find = true;
                _ans |= 1 << (d - 1);
                ans = min(ans, _ans);
            }
        }
        
        return make_pair(valg = find, valf = ans);
    }
};
