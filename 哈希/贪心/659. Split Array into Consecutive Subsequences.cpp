class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> appear, last;
        for (int i : nums) appear[i]++;

        for (int i : nums) {if (appear[i] == 0) continue;
            if (last[i - 1]) {
                last[i - 1]--;
                last[i]++;
                appear[i]--;
            } else {
                if (appear[i + 1] && appear[i + 2]) {
                    last[i + 2]++;
                    appear[i]--;
                    appear[i + 1]--;
                    appear[i + 2]--;
                    } else return false;
                }
            }
        return true;
    }
};
