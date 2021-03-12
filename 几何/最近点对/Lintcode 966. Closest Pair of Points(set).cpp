class Solution {
public:
    /**
     * @param x: the list of coordinate x
     * @param y: the list of coordinate x
     * @return: find the closest pair of points and return the distance
     */
    double getClosestDistance(vector<double> &x, vector<double> &y) {
        double ans = numeric_limits<double>::max();
        const int n = x.size();
        vector<PDD> all;
        
        for (int i = 0; i < n; i++) all.emplace_back(x[i], y[i]);
        sort(all.begin(), all.end());
        
        multiset<PDD, cmp_y> cur;
        for (int l = 0, r = 0; r < n; r++) {
            while (l < r && all[r].first - all[l].first > ans) {
                cur.erase(cur.lower_bound(all[l]));
                l++;
            }
            
            for (auto it = cur.lower_bound({ all[r].first, all[r].second - ans }); it != cur.end() && it->second < all[r].second + ans; it++) {
                ans = min(ans, dist(*it, all[r]));
            }
            cur.insert(all[r]);
        }
        return ans;
    }
private:
    typedef pair<double, double> PDD;
    double dist(const PDD& $1, const PDD& $2) {
        double x1, x2, y1, y2;
        tie(x1, y1) = $1;
        tie(x2, y2) = $2;
        
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    
    struct cmp_y {
        bool operator() (const PDD& $1, const PDD& $2) const {
            return $1.second < $2.second;
        }
    };
};
