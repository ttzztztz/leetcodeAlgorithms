class Solution {
public:
    bool check(vector<int>& nums, int length, const int state) {
        for (int i = 0; i < nums.size(); i++) {
            if (state & (1 << i)) {
                length -= nums[i];
            }

            if (length < 0) {
                return false;
            }
        }
        return length == 0;
    }
    bool makesquare(vector<int>& nums) {
        const int N = nums.size(), mask = (1 << N) - 1;
        vector<bool> memo1(1 << N + 1, false), memo2(1 << N + 1, false);

        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 4) return false;
        const int length = sum / 4;

        for (int state = 0; state <= (1 << N) - 1; state++) {
            memo1[state] = check(nums, length, state);
        }

        for (int state = 0; state <= (1 << N) - 1; state++) {
            if (!check(nums, sum / 2, state)) continue;

            bool isOK = false;
            for (int current = state; current; current = state & (current - 1)) {
                if (memo1[current] && memo1[state ^ current]) {
                    isOK = true;
                    break;
                }
            }
            memo2[state] = isOK;

            if (memo2[mask ^ state] && memo2[state]) {
                return true;
            }
        }

        return false;
    }
};