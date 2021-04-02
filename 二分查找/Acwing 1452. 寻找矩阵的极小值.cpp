// Forward declaration of queryAPI.
// int query(int x, int y);
// return int means matrix[x][y].

class Solution {
public:
    vector<int> getMinimumValue(int n) {
        int l = 0, r = n - 1;
        while (l <= r) {
            const int i = (l + r) / 2;
            int min_val = numeric_limits<int>::max();
            int min_idx = 0;
            for (int j = 0; j < n; j++) {
                const int t = query(i, j);
                if (t < min_val) {
                    min_val = t;
                    min_idx = j;
                }
            }
            
            if (i - 1 >= 0 && query(i - 1, min_idx) < min_val) {
                r = i - 1;
                continue;
            }
            if (i + 1 < n && query(i + 1, min_idx) < min_val) {
                l = i + 1;
                continue;
            }
            return { i, min_idx };
        }
        return {};
    }
};