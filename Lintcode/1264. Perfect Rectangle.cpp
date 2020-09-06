class Solution {
public:
    /**
     * @param rectangles: N axis-aligned rectangles
     * @return: if they all together form an exact cover of a rectangular region
     */
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        int x_min = numeric_limits<int>::max(), x_max = numeric_limits<int>::min();
        int y_min = numeric_limits<int>::max(), y_max = numeric_limits<int>::min();
        int square = 0;
        for (const vector<int>& r : rectangles) {
            if (!place(r[0], r[1], 1)) return false;
            if (!place(r[2], r[3], 2)) return false;
            if (!place(r[0], r[3], 4)) return false;
            if (!place(r[2], r[1], 8)) return false;
            
            x_min = min(x_min, r[0]);
            x_max = max(x_max, r[2]);
            y_min = min(y_min, r[1]);
            y_max = max(y_max, r[3]);
            square += (r[2] - r[0]) * (r[3] - r[1]);
        }
        
        unordered_map<int, int> stat;
        for (auto& p : hash) stat[p.second]++;
        return square == (x_max - x_min) * (y_max - y_min) && (stat[1] == 1 && stat[2] == 1 && stat[4] == 1 && stat[8] == 1);
    }
private:
    unordered_map<string, int> hash;
    string ID(int x, int y) {
        string answer;
        answer += to_string(x);
        answer += ',';
        answer += to_string(y);
        return answer;
    }
    bool place(int x, int y, int mask) {
        const string key = ID(x, y);
        if (hash.count(key) && hash[key] & mask) return false;
        hash[key] |= mask;
        return true;
    }
};
