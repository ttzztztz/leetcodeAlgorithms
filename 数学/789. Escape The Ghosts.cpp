class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        for (auto& ghost : ghosts) {
            if (dist(target, ghost[0], ghost[1]) <= dist(target, 0, 0)) return false;
        }
        return true;
    }
private:
    int dist(const vector<int>& target, int i, int j) {
        return abs(target[0] - i) + abs(target[1] - j);
    }
};