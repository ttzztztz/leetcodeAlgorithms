class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        const int N = input.size();
        dp = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(N + 1, vector<int>{}));
        return dfs(input, 0, N - 1);
    }
    
private:
    vector<vector<vector<int>>> dp;
    vector<int> dfs(const string& input, int left, int right) {
        if (!dp[left][right].empty()) {
            return dp[left][right];
        }
        
        vector<int> answer;
        if (left > right) {
            return answer;
        }
        
        bool find = false;
        for (int i = left + 1; i <= right - 1; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                find = true;
                vector<int> l = dfs(input, left, i - 1);
                vector<int> r = dfs(input, i + 1, right);
                
                for (int a = 0; a < l.size(); a++) {
                    for (int b = 0; b < r.size(); b++) {
                        if (input[i] == '+') {
                            answer.push_back(l[a] + r[b]);
                        } else if (input[i] == '-') {
                            answer.push_back(l[a] - r[b]);
                        } else if (input[i] == '*') {
                            answer.push_back(l[a] * r[b]);
                        }
                    }
                }
            }
        }
        
        if (!find) {
            answer.push_back(stoi(input.substr(left, right - left + 1)));
        }
        return dp[left][right] = answer;
    }
};
