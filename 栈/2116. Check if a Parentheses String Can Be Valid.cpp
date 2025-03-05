class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int n = s.size();
        if (n % 2 == 1) return false;

        int unlocked_cnt = 0, locked_balance = 0;
        for (int i = 0; i < n; i++) {
            const bool is_locked = locked[i] == '1';

            if (!is_locked) {
                unlocked_cnt++;
            } else {
                if (s[i] == '(') locked_balance++;
                else {
                    locked_balance--;
                    if (locked_balance < 0 && unlocked_cnt < -locked_balance) return false;
                }
            }
        }

        unlocked_cnt = 0, locked_balance = 0;
        for (int i = n - 1; i >= 0; i--) {
            const bool is_locked = locked[i] == '1';

            if (!is_locked) {
                unlocked_cnt++;
            } else {
                if (s[i] == ')') locked_balance++;
                else {
                    locked_balance--;
                    if (locked_balance < 0 && unlocked_cnt < -locked_balance) return false;
                }
            }
        }

        return true;
    }
};