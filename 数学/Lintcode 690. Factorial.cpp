class Solution {
public:
    /**
     * @param n: an integer
     * @return:  the factorial of n
     */
    string factorial(int n) {
        string cur = "1";
        for (int i = 2; i <= n; i++) {
            string $2 = to_string(i);
            cur = mul(cur, $2);
        }
        return cur;
    }
private:
    string mul(string $1, string $2) {
        string ans($1.size() + $2.size(), 0);
        reverse($1.begin(), $1.end());
        reverse($2.begin(), $2.end());
        
        
        for (int i = 0; i < $1.size(); i++) {
            const int d1 = $1[i] - '0';
            for (int j = 0; j < $2.size(); j++) {
                const int d2 = $2[j] - '0';
                
                ans[i + j] += d1 * d2;
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] %= 10;
            }
        }
        
        for (char& ch : ans) ch += '0';
        for (int i = 0; i < $1.size() + $2.size() - 1; i++) {
            if (ans.back() == '0') ans.pop_back();
            else break;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
