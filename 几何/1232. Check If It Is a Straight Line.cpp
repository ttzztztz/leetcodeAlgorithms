class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) return true;
        
        if (coordinates[0][0] == coordinates[1][0]) {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][0] != coordinates[0][0]) return false;
            }
            return true;
        } else {
            const double k = (1.0 * (coordinates[0][1] - coordinates[1][1])) / (1.0 * (coordinates[0][0] - coordinates[1][0]));
            const double b = 1.0 * coordinates[1][1] - k * coordinates[1][0];
            
            for (int i = 2; i < coordinates.size(); i++) {
                if (abs(1.0 * coordinates[i][1] - k * coordinates[i][0] - b) > 1e-6) return false;
            }
            
            return true;
        }
    }
};
