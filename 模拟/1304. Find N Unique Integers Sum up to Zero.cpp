class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> answer(n, 0);

        if (n % 2 == 1) { // odd
            for (int i = 2, j = 1; j < n; i++, j++) {
                if (i % 2) {
                    answer[j] = -(i / 2);
                } else {
                    answer[j] = i / 2;
                }
            }
        } else { // even
            for (int i = 2, j = 0; j < n; j++, i++) {
                if (i % 2) {
                    answer[j] = -(i / 2);
                } else {
                    answer[j] = i / 2;
                }
            }
        }

        return answer;
    }
};