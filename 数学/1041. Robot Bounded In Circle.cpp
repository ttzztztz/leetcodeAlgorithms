class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, -1, 0, 1};
        
        for (const char ch : instructions) {
            if (ch == 'G') {
                x += dx[dir];
                y += dy[dir];
            } else if (ch == 'L') {
                dir++;
                if (dir >= 4) dir -= 4;
            } else if (ch == 'R') {
                dir--;
                if (dir < 0) dir += 4;
            }
        }
        
        return (x == 0 && y == 0) || dir != 0;
    }
};
