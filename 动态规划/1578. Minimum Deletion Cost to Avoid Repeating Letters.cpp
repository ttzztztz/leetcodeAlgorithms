class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        memset(f, 0xff, sizeof f);
        this->cost = cost;
        this->s = s;
        return dfs(0, 27);
    }
private:
    int f[100005][28];
    vector<int> cost;
    string s;
    int dfs(int i, int last) {
        if (i == s.size()) return 0;
        int& val = f[i][last];
        if (val != -1) return val;
        
        int answer = numeric_limits<int>::max();
        if (s[i] - 'a' == last) {
            answer = min(answer, cost[i] + dfs(i + 1, last));
        } else {
            answer = min(cost[i] + dfs(i + 1, last), dfs(i + 1, s[i] - 'a'));
        }
        return val = answer;
    }
};
