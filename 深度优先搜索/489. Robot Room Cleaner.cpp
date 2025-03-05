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
        visited.insert(hash(0, 0));
        dfs(robot, 0, 0, 0);
    }
private:
    unordered_set<string> visited;

    string hash(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }

    void dfs(Robot& robot, int i, int j, int dir) {
        robot.clean();

        const int dx[] = { 0, 1, 0, -1 };
        const int dy[] = { -1, 0, 1, 0 };
        for (int k = 0; k < 4; k++) {
            const int next_dir = (dir + k) % 4;
            const int next_x = i + dx[next_dir], next_y = j + dy[next_dir];

            if (!visited.count(hash(next_x, next_y)) && robot.move()) {
                visited.insert(hash(next_x, next_y));
                dfs(robot, next_x, next_y, next_dir);
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