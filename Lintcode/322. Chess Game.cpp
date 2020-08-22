class Solution {
public:
    /**
     * @param queen: queen‘coordinate
     * @param knight: knight‘coordinate
     * @return: if knight is attacked please return true，else return false
     */
    vector<bool> isAttacked(vector<vector<int>> &queen, vector<vector<int>> &knight) {
        const int m = knight.size();
        vector<bool> answer(m, false);
        
        unordered_map<int, vector<int>> line, col, dig1, dig2;
        for (int i = 0; i < m; i++) {
            const int x = knight[i][0], y = knight[i][1];
            
            line[x].push_back(i);
            col[y].push_back(i);
            dig1[y - x].push_back(i);
            dig2[y + x].push_back(i);
        }
        
        for (int a = 0; a < queen.size(); a++) {
            const int x = queen[a][0], y = queen[a][1];
            
            if (line.count(x)) for (int i : line[x]) answer[i] = true;
            if (col.count(y)) for (int i : col[y]) answer[i] = true;
            if (dig1.count(y - x)) for (int i : dig1[y - x]) answer[i] = true;
            if (dig2.count(y + x)) for (int i : dig2[y + x]) answer[i] = true;
        }
        
        return answer;
    }
};
