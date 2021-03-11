class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> stk, ans;
        const int n = points.size();
        unordered_set<int> used;
        
        for (int i = 0; i < n; i++) {
            while (stk.size() >= 2 && orientation(stk[stk.size() - 2], stk[stk.size() - 1], points[i]) < 0) {
                stk.pop_back();
            }
            stk.push_back(points[i]);
        }
        
        stk.pop_back();
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() >= 2 && orientation(stk[stk.size() - 2], stk[stk.size() - 1], points[i]) < 0) {
                stk.pop_back();
            }
            stk.push_back(points[i]);
        }
        
        for (auto& point : stk) {
            const int h = hash(point);
            if (!used.count(h)) {
                used.insert(h);
                ans.push_back(point);
            }
        }
        return ans;
    }
private:
    int hash(const vector<int>& val) {
        return val[0] * 105 + val[1];
    }
    int orientation(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        const int px = p[0], py = p[1];
        const int qx = q[0], qy = q[1];
        const int rx = r[0], ry = r[1];
        
        return (qx - px) * (ry - qy) - (qy - py) * (rx - qx);
    }
};