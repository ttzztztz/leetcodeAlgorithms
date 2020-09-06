class Solution {
public:
    int minDays(int n) {
        dfs(n, 0);
        return answer;
    }
private:
    long long answer = 999999999;
    typedef long long ll;
    unordered_map<int, int> visited;
    
    void dfs(int n, int days) {
        if (days > answer || n < 0) return;
        if (visited.count(n) && visited[n] <= days) return;
        
        visited[n] = days;
        answer = min(answer, ll(days + n));
        if (n <= 1) return;
        
        if (n % 2 == 0) dfs(n / 2, days + 1);
        if (n % 3 == 0) dfs(n / 3, days + 1);
        
        if (n % 2 == 1 || n % 3 == 1) dfs(n - 1, days + 1);
        if (n % 3 == 2) dfs(n - 2, days + 2);
    }
};
