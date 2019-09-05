class Solution {
public:
    int stoneCount;
    int memory[1105][3305];

    bool dfs(vector<int>& stones, int index, int step) {
        if (step <= 0 || index > stoneCount) {
            return false;
        }

        if (index == stoneCount) {
            return true;
        }

        if (memory[index][step]) {
            return memory[index][step] == 1;
        }

        auto it = std::lower_bound(stones.begin(), stones.end(), step + stones[index - 1]);
        int nextIndex = it - stones.begin() + 1;

        if (it == stones.end() || step + stones[index - 1] != *it) {
            memory[index][step] = 2;
            // ø…–––‘ºÙ÷¶
            return false;
        } else {
            memory[index][step] = (dfs(stones, nextIndex, step - 1) || dfs(stones, nextIndex, step) || dfs(stones, nextIndex, step + 1)) ? 1 : 2;
            return memory[index][step] == 1;
        }
    }

    bool canCross(vector<int>& stones) {
        stoneCount = stones.size();

        if (stoneCount == 0 || stoneCount == 1) {
            return true;
        }
        if (stoneCount == 2) {
            return stones[1] == 1;
        }

        return dfs(stones, 1, 1);
    }
};