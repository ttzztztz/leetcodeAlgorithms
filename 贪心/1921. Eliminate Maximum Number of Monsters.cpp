class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        typedef long long ll;
        
        const int n = dist.size();
        vector<vector<ll>> data;
        for (int i = 0; i < n; i++) data.push_back(vector<ll>{dist[i], speed[i]});
        
        sort(data.begin(), data.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return lhs[0] * rhs[1] < lhs[1] * rhs[0];
        });
        
        int ans = 0;
        for (int i = 0, last = 0; i < n; i++) {
            ll t = data[i][0] / data[i][1];
            if (data[i][0] % data[i][1]) t++;
            
            if (last < t) {
                last++;
                ans++;
            } else break;
        }
        return ans;
    }
};