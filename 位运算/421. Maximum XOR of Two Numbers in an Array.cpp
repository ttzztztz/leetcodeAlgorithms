class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int answer = 0, bit = 0;

        for (int i = 31; i >= 0; i--) {
            bit |= 1 << i;

            unordered_set<int> hashSet;
            for (int num : nums) {
                hashSet.insert(num & bit);
            }

            int currentAnswer = answer | (1 << i);
            for (int item : hashSet) {
                if (hashSet.count(item ^ currentAnswer)) {
                    answer = currentAnswer;
                    break;
                }
            }

        }
        return answer;
    }
};