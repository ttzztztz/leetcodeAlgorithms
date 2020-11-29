class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        this->arr = arr;
        const int n = arr.size();
        f = vector<vector<PLL>>(n, vector<PLL>(n, init));
        return dfs(0, n - 1).first;
    }
private:
    typedef long long ll;
    typedef pair<ll, ll> PLL;
    const PLL init = {-1, -1};
    vector<vector<PLL>> f;
    
    vector<int> arr;
    PLL dfs(int i, int j) {
        if (i == j) {
            return { 0, arr[i] };
        }
        if (i + 1 == j) {
            return { arr[i] * arr[j], max(arr[i], arr[j]) };
        }
        
        PLL& val = f[i][j];
        if (val != init) return val;
        
        ll min_sum = numeric_limits<ll>::max(), max_val = 0;
        for (int k = i; k + 1 <= j; k++) {
            auto [sum1, mx1] = dfs(i, k);
            auto [sum2, mx2] = dfs(k + 1, j);
            
            const ll cur_sum = sum1 + sum2 + mx1 * mx2, cur_max = max(mx1, mx2);
            if (cur_sum < min_sum) {
                min_sum = cur_sum;
                max_val = cur_max;
            } else if (cur_sum == min_sum) {
                max_val = min(max_val, cur_max);
            }
        }
        
        return val = { min_sum, max_val };
    }
};
