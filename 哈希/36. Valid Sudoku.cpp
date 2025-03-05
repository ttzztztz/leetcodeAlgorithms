class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9), col(9), section(9);

        for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
            const char ch = board[i][j];
            const int section_id = (i / 3) * 3 + (j / 3);
            const int d = ch - '0';

            if (ch == '.') continue;

            if (row[i].count(d)) return false;
            row[i].insert(d);
            if (col[j].count(d)) return false;
            col[j].insert(d);
            if (section[section_id].count(d)) return false;
            section[section_id].insert(d);
        }
        return true;
    }
};