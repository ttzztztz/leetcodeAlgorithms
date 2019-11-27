class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        const int N = customers.size();
        int basic = 0, maxAdd = 0, currentAdd = 0;
        for (int i = 0; i < N; i++) {
            if (grumpy[i] == 0) {
                basic += customers[i];
            }
        }

        int left = 0, right = 0;
        for (; right < X; right++) {
            if (grumpy[right]) {
                currentAdd += customers[right];
            }
        }

        maxAdd = currentAdd;

        for (; right < N; right++, left++) {
            if (grumpy[right]) {
                currentAdd += customers[right];
            }

            if (grumpy[left]) {
                currentAdd -= customers[left];
            }

            maxAdd = max(currentAdd, maxAdd);
        }
        return basic + maxAdd;
    }
};