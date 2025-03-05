class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        vector<int> stk;

        int last_ts = 0;
        for (auto& log : logs) {
            auto [function_id, kind, ts] = parse_log(log);

            if (kind == fn_start) {
                if (!stk.empty()) ans[stk.back()] += ts - last_ts;
                stk.push_back(function_id);
            } else {
                auto fn = stk.back();
                stk.pop_back();
                ans[fn] += ts - last_ts;
            }
            last_ts = ts;
        }
        return ans;
    }
private:
    const int fn_start = 0;
    const int fn_end = 1;
    // {function_id, start|end, ts}
    tuple<int, int, int> parse_log(const string& str) {
        vector<string> ans;
        string buf;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ':') buf += str[i];

            if (str[i] == ':' || i == str.size() - 1) {
                ans.push_back(buf);
                buf.clear();
            }
        }

        if (ans[1] == "start") return { stoi(ans[0]), fn_start, stoi(ans[2]) };
        return { stoi(ans[0]), fn_end, stoi(ans[2]) + 1 };
    }
};