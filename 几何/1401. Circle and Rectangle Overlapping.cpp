class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        const int x_near = maxDist(x1, x2, x_center);
        const int y_near = maxDist(y1, y2, y_center);
        
        return (x_near - x_center) * (x_near - x_center) + (y_near - y_center) * (y_near - y_center) <= radius * radius;
    }
    int maxDist(int left, int right, int circle) {
        return max(min(right, circle), left);
    }
};
