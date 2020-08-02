class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        v[0] = nums1, v[1] = nums2;
        N = nums1.size(), M = nums2.size();
        memset(f, 0xff, sizeof f);
        return max(dfs(0, 0), dfs(0, 1)) % mod;
    }
private:
    long long f[100005][2];
    const int mod = 1e9+7;
    int N, M;
    vector<int> v[2];
    long long dfs(int i, int k) {
        if (i == v[k].size()) return 0;
        long long& val = f[i][k];
        if (val != -1) return val;
        
        long long answer = 0;
        answer = max(answer, v[k][i] + dfs(i + 1, k));
        auto it = lower_bound(v[k ^ 1].begin(), v[k ^ 1].end(), v[k][i]);
        if (it != v[k ^ 1].end() && *it == v[k][i]) {
            answer = max(answer, v[k][i] + dfs(it + 1 - v[k ^ 1].begin(), k ^ 1));
        }
        return val = answer;
    }
};