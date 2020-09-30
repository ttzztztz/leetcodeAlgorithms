class Solution {
public:
    /**
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        this->num = num, this->n = num.size(), this->target = target;
        
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            if (i >= 1 && num[0] == '0') break;

            state.push_back(num[i]);
            cur = cur * 10 + (num[i] - '0');
            dfs(i + 1, cur, cur);
        }
        return answer;
    }
private:
    vector<string> answer;
    string state, num;
    int n, target;
    typedef long long ll;
    
    void dfs(int idx, ll prev, ll cur) {
        if (idx == n) {
            if (cur == target) answer.push_back(state);
            return;
        }
        
        ll nxt = 0;
        for (int i = idx; i < n; i++) {
            if (i >= idx + 1 && num[idx] == '0') break;
            nxt = nxt * 10 + (num[i] - '0');
            
            // +
            string _add = "+" + to_string(nxt);
            state += _add;
            dfs(i + 1, nxt, cur + nxt);
            for (int _ = 0; _ < _add.size(); _++) state.pop_back();
            
            // -
            _add = "-" + to_string(nxt);
            state += _add;
            dfs(i + 1, -nxt, cur - nxt);
            for (int _ = 0; _ < _add.size(); _++) state.pop_back();
            
            // *
            _add = "*" + to_string(nxt);
            state += _add;
            dfs(i + 1, prev * nxt, cur - prev + prev * nxt);
            for (int _ = 0; _ < _add.size(); _++) state.pop_back();
        }
    }
};
