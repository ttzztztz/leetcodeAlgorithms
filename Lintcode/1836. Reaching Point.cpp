class Solution {
public:
    /**
     * @param start: a point [x, y]
     * @param target: a point [x, y]
     * @return: return True or False
     */
    bool ReachingPoints(vector<int> &start, vector<int> &target) {
        if (start == target) return true;
        while (true) {
            if (target[0] < start[0] || target[1] < start[1]) return false;
            if (start == target) return true;
            
            vector<int> nxt{0, 0};
            if (target[0] > target[1]) {
                nxt[0] = target[0] - target[1];
                nxt[1] = target[1];
            } else {
                nxt[0] = target[0];
                nxt[1] = target[1] - target[0];
            }
            target = nxt;
        }
        
        return false;
    }
};
