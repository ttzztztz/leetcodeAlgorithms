class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
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
            int n = 0, last = -1;
            for (pair<int, int> dist : distribution) {
                if (n >= k) {
                    break;
                }

                if (distribution[dist.first] == 0) {
                    continue;
                }

                distribution[dist.first]--;
                rest--;

                if (n >= 1 && last + 1 != dist.first) {
                    return false;
                }
                n++;
                last = dist.first;
            }
        }

        return true;
    }
};