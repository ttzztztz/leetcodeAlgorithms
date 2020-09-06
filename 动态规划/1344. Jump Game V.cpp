class Solution {
public:
    int N;
    vector<int> dp;
    bool debug = false;
    int dfs(const vector<int>& arr, const int d, int i) {
        if (debug) {
            cout << i << endl;
        }
        if (dp[i] != -1) {
            if (debug) cout << i << ", " << dp[i] << endl;
            return dp[i];
        }
        
        int answer = 1, jmp_cnt = 0;
        // jump left
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] >= arr[i] || jmp_cnt >= d) break;
            
            answer = max(answer, 1 + dfs(arr, d, j));
            jmp_cnt++;
        }
        
        // jump right
        jmp_cnt = 0;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] >= arr[i] || jmp_cnt >= d) break;
            
            answer = max(answer, 1 + dfs(arr, d, j));
            jmp_cnt++;
        }
        
        if (debug) {
            cout << "ok" << i << " " << answer << endl;
        }
        return dp[i] = answer;
    }
    int maxJumps(vector<int>& arr, int d) {
        N = arr.size();
        dp = vector<int>(1005, -1);
        
        int answer = 0;
        for (int i = N - 1; i >= 0; i--) {
            answer = max(answer, dfs(arr, d, i));
        }
        return answer;
    }
};
