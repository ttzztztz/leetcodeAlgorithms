class Solution {
public:
    vector<vector<int>> answer;
    void dfs(vector<int>& temp, int i, int k, int n) {
        if (n < 0 || k < 0) {
            return;
        }
        if (n == 0 && k == 0) {
            answer.push_back(temp);
            return;
        }
        if (i >= 10) {
            return;
        }

        temp.push_back(i);
        dfs(temp, i + 1, k - 1, n - i);
        temp.pop_back();

        dfs(temp, i + 1, k, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;

        dfs(temp, 1, k, n);
        return answer;
    }
};