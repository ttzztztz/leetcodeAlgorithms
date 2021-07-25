class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        typedef long long ll;
        vector<vector<ll>> ans;
        
        unordered_map<int, vector<int>> cols;
        const int n = segments.size();
        const int maxn = 100000;
        vector<ll> diff(maxn + 1, 0);
        vector<int> points;
        for (auto& seg : segments) {
            diff[seg[0]] += seg[2];
            diff[seg[1]] -= seg[2];
            
            cols[seg[0]].push_back(seg[2]);
            points.push_back(seg[0]);
            points.push_back(seg[1]);
        }
        
        for (int i = 1; i <= maxn; i++) {
            diff[i] += diff[i - 1];
        }
        
        int start = 0;
        sort(points.begin(), points.end());
        for (int i : points) {
            if (diff[i] != diff[start] || (diff[i] == diff[start] && cols[i] != cols[start])) {
                if (diff[start] > 0) ans.push_back(vector<ll>{ start, i, diff[start] });
                start = i;
            }
        }
        
        return ans;
    }
};