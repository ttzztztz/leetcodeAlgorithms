class Solution {
public:
    int answer = 0;
    void dfs(int u, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        answer += candies[u];
        candies[u] = 0;

        for (int key : keys[u]) {
            status[key] = 1;
        }

        for (int contain : containedBoxes[u]) {
            initialBoxes.push_back(contain);
        }

        keys[u].clear();
    }

    bool solve(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int lastAnswer = answer;
        vector<int> copyInitialBoxes = initialBoxes;
        vector<int> toBeDone;
        initialBoxes.clear();

        for (int box : copyInitialBoxes) {
            if (!status[box]) {
                initialBoxes.push_back(box);
            } else {
                toBeDone.push_back(box);
            }
        }

        for (int box : toBeDone) {
            dfs(box, status, candies, keys, containedBoxes, initialBoxes);
        }
        return answer > lastAnswer;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        while (solve(status, candies, keys, containedBoxes, initialBoxes)) {}
        return answer;
    }
};