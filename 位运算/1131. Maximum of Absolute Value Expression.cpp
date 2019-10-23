class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int answer = 0;
        const int N = arr1.size();

        for (int j = 0; j < (1 << 3); j++) {
            int _max = -99999999, _min = 999999999;
            for (int i = 0; i < N; i++) {
                int current = 0;

                for (int k = 0; k < 3; k++) {
                    if (j & (1 << k)) {
                        if (k == 0) {
                            current += arr1[i];
                        } else if (k == 1) {
                            current += arr2[i];
                        } else {
                            current += i;
                        }
                    } else {
                        if (k == 0) {
                            current -= arr1[i];
                        } else if (k == 1) {
                            current -= arr2[i];
                        } else {
                            current -= i;
                        }
                    }
                }

                _max = std::max(_max, current);
                _min = std::min(_min, current);
            }

            answer = std::max(_max - _min, answer);
        }

        return answer;
    }
};