class Solution {
public:
    Solution(double radius, double x_center, double y_center) : r(radius), x(x_center), y(y_center) {
        d1 = uniform_real_distribution<double>(x - r, x + r);
        d2 = uniform_real_distribution<double>(y - r, y + r);
    }
    
    vector<double> randPoint() {
        vector<double> ans(2, 0.0);
        do {
            ans[0] = d1(rd);
            ans[1] = d2(rd);
        } while (dist(ans) > r * r);
        return ans;
    }
private:
    double r, x, y;
    double dist(const vector<double>& data) {
        return (data[0] - x) * (data[0] - x) + (data[1] - y) * (data[1] - y);
    }
    
    mt19937 rd{ random_device{}() };
    uniform_real_distribution<double> d1, d2;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */