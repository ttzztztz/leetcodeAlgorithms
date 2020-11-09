class Solution {
public:
    /**
     * @param x: the list of coordinate x
     * @param y: the list of coordinate x
     * @return: find the closest pair of points and return the distance
     */
    double getClosestDistance(vector<double> &x, vector<double> &y) {
        const int n = x.size();
        for (int i = 0; i < n; i++) all.emplace_back(x[i], y[i]);
        sort(all.begin(), all.end(), [](const auto& $1, const auto& $2) -> bool {
            return ($1.first < $2.first) || ($1.first == $2.first && $1.second < $2.second);
        });

        recursion(0, n - 1);
        return ans;
    }

private:
    typedef pair<double, double> PDD;
    vector<PDD> all;
    double ans = 1e20;

    void recursion(int i, int j) {
        auto cmp_y = [](const PDD& $1, const PDD& $2) -> bool {
            return $1.second < $2.second;
        };

        if (j - i <= 3) {
            for (int a = i; a <= j; a++) {
                for (int b = a + 1; b <= j; b++) {
                    ans = min(ans, dist(all[a], all[b]));
                }
            }
            sort(all.begin() + i, all.begin() + j + 1, cmp_y);
            return;
        }

        const int mid = (i + j) / 2;
        const int mid_x = all[mid].first;

        recursion(i, mid), recursion(mid + 1, j);
        vector<PDD> tmp(j - i + 1);
        merge(all.begin() + i, all.begin() + mid + 1,
              all.begin() + mid + 1, all.begin() + j + 1,
              tmp.begin(), cmp_y);
        copy(tmp.begin(), tmp.end(), all.begin() + i);

        tmp.clear();
        for (int a = i; a <= j; a++) {
            if (abs(all[a].first - mid_x) < ans) {
                const int m = tmp.size();
                for (int b = m - 1; b >= 0 && all[a].second - tmp[b].second < ans; b--) {
                    ans = min(ans, dist(all[a], tmp[b]));
                }
                tmp.push_back(all[a]);
            }
        }
    }

    double dist(const PDD &$1, const PDD &$2) {
        double x1, x2, y1, y2;
        tie(x1, y1) = $1;
        tie(x2, y2) = $2;

        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
};
