class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }
        int answer = 1;
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }

        for (int num : nums) {
            int currentAnswer = 1;
            if (set.count(num - 1)) {
                continue;
            }

            while (set.count(num + 1)) {
                num++;
                currentAnswer++;
            }

            answer = std::max(answer, currentAnswer);
        }

        return answer;
    }
};