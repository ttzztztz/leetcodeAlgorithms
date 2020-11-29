class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
		const int n = arr.size();
		vector<int> f(n, 0), g(n, 0);
		
		vector<int> stk;
		for (int i = 0; i < n; i++) {
			while (!stk.empty() && arr[stk.back()] >= arr[i]) stk.pop_back();
			
            if (stk.empty()) f[i] = -1;
            else f[i] = stk.back();
			stk.push_back(i);
		}

		stk.clear();
		for (int i = n - 1; i >= 0; i--) {
			while (!stk.empty() && arr[stk.back()] > arr[i]) stk.pop_back();
			if (stk.empty()) g[i] = n;
			else g[i] = stk.back();
			stk.push_back(i);
        }

		typedef long long ll;
		ll ans = 0;
		const int mod = 1e9+7;
		for (int i = 0; i < n; i++) {
			const int l = i - f[i], r = g[i] - i;
			ans = (ans + 1ll * arr[i] * l * r) % mod;
		}
		return ans;
    }
};


