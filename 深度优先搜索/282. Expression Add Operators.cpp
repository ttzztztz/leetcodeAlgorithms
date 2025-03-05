class Solution {
public:
    vector<string> addOperators(string num, int target) {
        string cur;
        dfs(num, target, 0, cur, 0, 0);
        return ans;
    }
private:
    vector<string> ans;
    typedef long long ll;

    void dfs(const string& num, ll target, ll res, string& cur, int idx, ll last) {
        if (idx >= num.size()) {
            if (target == res) ans.push_back(cur);
            return;
        }

        ll buf = 0;
        for (int j = idx; j < num.size(); j++) {
            if (buf == 0 && j > idx) break; // remove leading 0
            buf = buf * 10 + num[j] - '0';

            const string cur_number = to_string(buf);
            const string prev_cur = cur;
            if (idx == 0) {
                cur += cur_number;
                dfs(num, target, buf, cur, j + 1, buf);
                cur = prev_cur;
                continue;
            }

            // add +
            cur += '+' + cur_number;
            dfs(num, target, res + buf, cur, j + 1, buf);
            cur = prev_cur;
            // add -
            cur += '-' + cur_number;
            dfs(num, target, res - buf, cur, j + 1, -buf);
            cur = prev_cur;

            // add *
            cur += '*' + cur_number;
            dfs(num, target, res - last + buf * last, cur, j + 1, buf * last);
            cur = prev_cur;
        }
    }
};