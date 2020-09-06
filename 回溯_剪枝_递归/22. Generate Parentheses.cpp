class Solution {
public:
    vector<string> answer;
    void dfs(int leftRemain, int rightRemain, string& state) {
        if (leftRemain == rightRemain && leftRemain == 0) {
            answer.push_back(state);
            return;
        }

        if (leftRemain) {
            state.push_back('(');
            dfs(leftRemain - 1, rightRemain + 1, state);
            state.pop_back();
        }
        if (rightRemain) {
            state.push_back(')');
            dfs(leftRemain, rightRemain - 1, state);
            state.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(n, 0, s);

        return answer;
    }
};