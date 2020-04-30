class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 0);
        return answer;
    }
private:
    vector<vector<int>> answer;
    vector<int> tmp;
    void dfs(const int n, const int k, int i) {
        if (i > n) return;
        if (tmp.size() == k) {
            answer.push_back(tmp);
            return;
        }
        
        for (int j = i + 1; j <= n; j++) {
            tmp.push_back(j);
            dfs(n, k, j);
            tmp.pop_back();
        }
    }
};
