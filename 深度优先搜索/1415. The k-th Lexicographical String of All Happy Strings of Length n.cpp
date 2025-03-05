class Solution {
public:
    string getHappyString(int n, int k) {
        this->k = k;
        string cur;
        dfs(cur, n);
        return ans;
    }
private:
    int k;
    string ans;

    void dfs(string& cur, const int n) {
        if (!ans.empty()) return;

        if (cur.size() == n) {
            k--;
            if (k == 0) ans = cur;
            return;
        }

        const char ch[] = { 'a', 'b', 'c' };
        for (int i = 0; i < 3; i++) {
            if (!cur.empty() && cur.back() == ch[i]) continue;
    
            cur += ch[i];
            dfs(cur, n);
            cur.pop_back();
        }
    }
};