/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        visited_.insert(Hash(0, 0));
        Dfs(0, 0, 0, robot);
    }
private:
    string Hash(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }
    unordered_set<string> visited_;
    
    void Dfs(int i, int j, int dir, Robot& robot) {
        robot.clean();
        const int kDx[] = {0, 1, 0, -1};
        const int kDy[] = {1, 0, -1, 0};
        
        for (int k = 0; k < 4; k++) {
            const int nx = i + kDx[(dir + k) % 4], ny = j + kDy[(dir + k) % 4];
            
            if (!visited_.count(Hash(nx, ny)) && robot.move()) {
                visited_.insert(Hash(nx, ny));
                Dfs(nx, ny, (dir + k) % 4, robot);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
            } else {
                robot.turnRight();
            }
        }
    }
};
