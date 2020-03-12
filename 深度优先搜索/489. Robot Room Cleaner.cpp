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
        dfs(robot, 0, 0, 0);
    }
private:
    unordered_set<string> visited;
    string ID(int i, int j) {
        string answer;
        answer += to_string(i);
        answer += ',';
        answer += to_string(j);
        return answer;
    }
    void dfs(Robot& robot, int i, int j, int dir) {
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[(dir + k) % 4], ny = j + dy[(dir + k) % 4];
            if (!visited.count(ID(nx, ny)) && robot.move()) {
                visited.insert(ID(nx, ny));
                
                dfs(robot, nx, ny, (dir + k) % 4);
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
