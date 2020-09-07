class Solution {
public:
    /**
     * @param lengths: the lengths of sticks at the beginning.
     * @return: return the minimum number of cuts.
     */
    int makeEquilateralTriangle(vector<int> &lengths) {
        // write your code here.
        map<int, int> m;
        for (int l : lengths) m[l]++;
        
        for (auto& p : m) {
            int v, app;
            tie(v, app) = p;
            
            if (app >= 3) return 0;
        }
        
        for (auto& p : m) {
            int v, app;
            tie(v, app) = p;
            
            if (app == 2 && m.upper_bound(v) != m.end()) {
                return 1;
            }
        }
        
        for (auto& p : m) {
            int v, app;
            tie(v, app) = p;
            
            if (m.count(v * 2)) {
                return 1;
            }
        }
        
        return 2;
    }
};
