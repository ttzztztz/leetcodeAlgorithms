class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> answer;

        for (int i = 1, j = 1000; i <= z; i++) {
            while (j > 1 && customfunction.f(i, j) > z) {
                j--;
            }
            if (customfunction.f(i, j) == z) {
                answer.push_back({i, j});
            }
        }

        return answer;
    }
};