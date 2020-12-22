class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        const int n = pushed.size();
        vector<int> stk;
        for (int i = 0, j = 0; i < n; i++) {
            stk.push_back(pushed[i]);
            while (j < n && !stk.empty() && stk.back() == popped[j]) {
                stk.pop_back();
                j++;
            }
        }
        return stk.empty();
    }
};
