class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        const int N = nums.size();
        if (N % k != 0) {
            return false;
        }

        map<int, int> distribution;
        int rest = N;
        for (int num : nums) {
            distribution[num]++;
        }

        while (rest) {
            for (int j = 0, i = distribution.begin()->first; j < k; j++, i++) {
                if (!distribution.count(i)) return false;

                distribution[i]--;
                if (distribution[i] == 0) {
                    distribution.erase(i);
                }
                rest--;
            }
        }

        return true;
    }
};