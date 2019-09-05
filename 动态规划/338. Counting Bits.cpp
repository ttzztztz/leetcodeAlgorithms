class Solution {
public:
    int lowbit (int x) {
        return x & (-x);
    }

    vector<int> countBits(int num) {
        if (num == 0) {
            return vector<int>({0});
        }
        vector<int> result;
        result.resize(num + 1);

        result[0] = 0;
        result[1] = 1;

        for (int i = 2; i <= num; i++) {
            int number = i, answer = 0;

            while (number) {
                if (number < i) {
                    answer += result[number];
                    break;
                } else {
                    answer++;
                    number -= lowbit(number);
                }
            }

            result[i] = answer;
        }

        return result;
    }
};