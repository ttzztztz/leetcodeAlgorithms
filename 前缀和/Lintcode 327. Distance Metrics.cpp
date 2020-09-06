class Solution {
public:
    /**
     * @param a: an integer array
     * @return: an integer array
     */
    vector<long long> getDistanceMetrics(vector<int> &a) {
        const int n = a.size();
        
        vector<long long> answer(n, 0);
        unordered_map<int, vector<int>> f;
        for (int i = 0; i < n; i++) {
            f[a[i]].push_back(i);
        }
        
        for (auto& p : f) {
            const vector<int>& v = p.second;
            const int m = v.size();
            
            long long cur = 0;
            for (int i : v) cur += i;
            
            cur -= 1ll * v[0] * m;
            answer[v[0]] = cur;
            
            for (int i = 1; i < m; i++) {
                cur -= 1ll * (m - i) * (v[i] - v[i - 1]);
                cur += 1ll * i * (v[i] - v[i - 1]);
                
                answer[v[i]] = cur;
            }
        }
        return answer;
    }
};
