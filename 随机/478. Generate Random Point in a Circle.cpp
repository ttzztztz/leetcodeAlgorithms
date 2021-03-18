class Solution {
public:
    Solution(double radius, double x_center, double y_center) : r(radius), x(x_center), y(y_center) {
        d = uniform_real_distribution<double>(0.0, 1.0);
    }
    
    vector<double> randPoint() {
        double c = r * sqrt(d(rd));
        double angle = 2.0 * M_PI * d(rd);
        
        return { x + c * cos(angle), y + c * sin(angle) };
    }
private:
    double r, x, y;
    mt19937 rd{ random_device{}() };
    uniform_real_distribution<double> d;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */