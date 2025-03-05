class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if (n == 0) return {};

        mapping = unordered_map<char, char>{
            { '0', '0' },
            { '1', '1' },
            { '6', '9' },
            { '8', '8' },
            { '9', '6' }
        };

        string cur;
        dfs(n, 0, cur);

        for (auto& [k, v] : mapping) {
            if (k == v) {
                string t;
                t += k;
                dfs(n, 1, t);
            }
        }
        return ans;
    }
private:
    vector<string> ans;
    unordered_map<char, char> mapping;

    void dfs(const int n, int cnt, string& cur) {
        if (cnt > n) return;
        if (cnt == n) {
            if (cur[0] == '0' && n >= 2) return;
            ans.push_back(cur);
            return;
        }

        for (auto [k, v] : mapping) {
            const string prev_cur = cur;
            cur = k + cur + v;
            dfs(n, cnt + 2, cur);
            cur = prev_cur;
        }
    }
};