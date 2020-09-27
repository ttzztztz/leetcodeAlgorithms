class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> stk;
        for (auto& log : logs) {
            if (log == "./") continue;
            else if (log == "../") {
                if (!stk.empty()) stk.pop_back();
            } else {
                stk.push_back(log);
            }
        }
        return stk.size();
    }
};
