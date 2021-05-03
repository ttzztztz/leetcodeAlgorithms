class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        this->n = arr.size(), this->d = d, this->arr = arr;
        this->f = vector<int>(n + 1, -1);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
private:
    int d, n;
    vector<int> arr, f;
    
    int dfs(int u) {
        int& val = f[u];
        if (val != -1) return val;
        int ans = 1;
        for (int i = 1; i <= d; i++) {
            if (u + i < n && arr[u] > arr[u + i]) {
                ans = max(ans, 1 + dfs(u + i));
            } else {
                break;
            }
        }
        
        for (int i = 1; i <= d; i++) {
            if (u - i >= 0 && arr[u] > arr[u - i]) {
                ans = max(ans, 1 + dfs(u - i));
            } else {
                break;
            }
        }
        return val = ans;
    }
    
};