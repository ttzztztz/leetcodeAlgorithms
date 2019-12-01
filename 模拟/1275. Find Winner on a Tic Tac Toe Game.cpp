class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        char map[3][3];
        memset(map, 0, sizeof(map));

        int i = 0;
        for (const vector<int>& move : moves) {
            char fill = 'A';
            if (i == 0) {
                fill = 'A';
            } else {
                fill = 'B';
            }
            i ^= 1;

            map[move[0]][move[1]] = fill;
        }

        for (int i = 0; i < 2; i++) {
            string fill = "A";
            if (i == 0) {
                fill = "A";
            } else {
                fill = "B";
            }

            for (int j = 0; j < 3; j++) {
                if (map[j][0] == map[j][1] && map[j][1] == map[j][2] && map[j][0] == fill[0]) {
                    return fill;
                }
                if (map[0][j] == map[1][j] && map[1][j] == map[2][j] && map[0][j] == fill[0]) {
                    return fill;
                }
            }

            if (map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[0][0] == fill[0]) {
                return fill;
            }
            if (map[0][2] == map[1][1] && map[1][1] == map[2][0] && map[0][2] == fill[0]) {
                return fill;
            }
        }

        if (moves.size() == 9) {
            return "Draw";
        } else {
            return "Pending";
        }
    }
};