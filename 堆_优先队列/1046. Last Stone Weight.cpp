class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }

        priority_queue<int, vector<int>, less<>> stoneSize;
        for (int stone : stones) {
            stoneSize.push(stone);
        }
        while (stoneSize.size() > 1) {
            int first = stoneSize.top();
            stoneSize.pop();
            int second = stoneSize.top();
            stoneSize.pop();

            if (first != second) {
                stoneSize.push(std::abs(first - second));
            }
        }

        if (stoneSize.size() == 0) {
            return 0;
        } else {
            return stoneSize.top();
        }
    }
};