class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        n = A.size();
        f = vector<int>(n, -1);
        b = B;
        a = A;
        
        deque<int> q;
        for (int i = 0; i < n; i++) {
            if (A[i] == -1) continue;
            
            while (!q.empty() && i - q.front() > B) q.pop_front();
            if (q.empty()) {
                f[i] = A[i];
            } else {
                f[i] = f[q.front()] + A[i];
            }
            while (!q.empty() && f[i] < f[q.back()]) q.pop_back();
            q.push_back(i);
        }
        
        dfs(0);
        return ans;
    }
private:
    vector<int> ans, f, a;
    int n, b;
    bool dfs(int i) {
        if (a[i] != -1 && f[i] != -1) ans.push_back(i + 1);
        else return false;

        if (i == n - 1) return true;
        for (int k = 1; i + k < n && k <= b; k++) {
            if (f[i] + a[i + k] == f[i + k] && dfs(i + k)) return true;
        }
        
        ans.pop_back();
        return false;
    }
};
