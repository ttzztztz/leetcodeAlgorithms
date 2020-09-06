class Solution {
public:
    vector<string> addOperators(string num, int target) {
        this->target = target;
        long long cur = 0;
        for (int i = 0; i < num.size(); i++) {
            if (i == 1 && num[0] == '0') break;
            cur *= 10;
            cur += num[i] - '0';
            
            string str = to_string(cur);
            dfs(num, i + 1, cur, cur, str);
        }
        return answer;
    }
private:
    vector<string> answer;
    int target;
    void dfs(const string& num, int index, long long total, long long pre, string& state) {
        if (index == num.size()) {
            if (target == total) answer.push_back(state);
            return;
        }
        long long cur = 0;
        for (int i = index; i < num.size(); i++) {
            if (i == index + 1 && num[index] == '0') break;
            cur *= 10;
            cur += num[i] - '0';
            
            string cur_str = "+" + to_string(cur);
            state += cur_str;
            dfs(num, i + 1, total + cur, cur, state);
            for (int _ = 0; _ < cur_str.size(); _++) state.pop_back();
            
            cur_str = "-" + to_string(cur);
            state += cur_str;
            dfs(num, i + 1, total - cur, -cur, state);
            for (int _ = 0; _ < cur_str.size(); _++) state.pop_back();
            
            cur_str = "*" + to_string(cur);
            state += cur_str;
            dfs(num, i + 1, total - pre + pre * cur, pre * cur, state);
            for (int _ = 0; _ < cur_str.size(); _++) state.pop_back();
        }
    }
};
