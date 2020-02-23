class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<bool>> validState;
    vector<int> appear;
    int N;
    bool isLarger(const vector<int>& $1, const vector<int>& $2) {
        int cnt1 = 0, cnt2 = 0;
        for (int i : $1) cnt1 += i;
        for (int i : $2) cnt2 += i;
        if (cnt1 != cnt2) return cnt1 > cnt2;
        
        vector<int> cp$1 = $1, cp$2 = $2;
        reverse(cp$1.begin(), cp$1.end());
        reverse(cp$2.begin(), cp$2.end());
        return cp$1 > cp$2;
    }
    vector<int> dfs(int u, int state) {
        if (u == 10) return state % 3 == 0 ? vector<int>(10, 0) : vector<int>{};
        if (validState[u][state]) return dp[u][state];
        
        vector<int> answer{};
        for (int i = 0; i <= appear[u]; i++) {
            vector<int> t = dfs(u + 1, (state + u * i) % 3);
            if (t.empty()) continue;
            
            t[u] += i;
            if (answer.empty() || isLarger(t, answer)) {
                answer = t;
            }
        }
        
        validState[u][state] = true;
        return dp[u][state] = answer;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        appear = vector<int>(10, 0);
        dp = vector<vector<vector<int>>>(10, vector<vector<int>>(3, vector<int>{}));
        validState = vector<vector<bool>>(10, vector<bool>(3, false));
        N = digits.size();
        for (int num : digits) appear[num]++;
        
        vector<int> answer = dfs(0, 0);
        if (answer.empty()) return "";
        string ans;
        for (int i = 9; i >= 0; i--) {
            string temp(answer[i], '0' + i);
            ans += temp;
        }
        while (ans.size() >= 2 && ans[0] == '0') ans.erase(ans.begin());
        return ans;
    }
};
