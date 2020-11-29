class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        const int n = arr.size();
        vector<int> f(n), g(n);
        
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.back()] <= arr[i]) stk.pop_back();
            
            if (stk.empty()) f[i] = -1;
            else f[i] = stk.back();
            
            stk.push_back(i);
        }
        
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.back()] < arr[i]) stk.pop_back();
            
            if (stk.empty()) g[i] = -1;
            else g[i] = stk.back();
            
            stk.push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mi = numeric_limits<int>::max();
            if (f[i] != -1) mi = min(mi, arr[f[i]]);
            if (g[i] != -1) mi = min(mi, arr[g[i]]);
            
            if (mi != numeric_limits<int>::max()) ans += mi * arr[i];
        }
        return ans;
    }
};
