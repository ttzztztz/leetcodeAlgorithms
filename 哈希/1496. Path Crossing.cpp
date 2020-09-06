class Solution {
public:
    unordered_set<string> visited;
    string hash(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }
    bool isPathCrossing(string path) {
        int i = 0, j = 0;
        for (const char& ch : path) {
            visited.insert(hash(i, j));
            if (ch == 'N') {
                i++;
            } else if (ch == 'S') {
                i--;
            } else if (ch == 'E') {
                j++;
            } else {
                j--;
            }
            if (visited.count(hash(i, j))) return true;
        }
        return false;
    }
};