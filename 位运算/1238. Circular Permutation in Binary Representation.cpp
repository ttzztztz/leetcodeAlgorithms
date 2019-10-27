class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> answer;
        const int MAX = (1 << n) - 1;
        vector<bool> used(MAX + 1, false);

        answer.resize(MAX + 1);
        answer[0] = start;
        answer[MAX] = (start & 1) ? (start ^ 1) : (start | 1);
        used[answer[0]] = used[answer[MAX]] = true;

        for (int i = 1; i < MAX; i++) {
            const int last = answer[i - 1];
            for (int j = 0; j < n; j++) {
                int prepare = 0;
                if (last & (1 << j)) {
                    prepare = last ^ (1 << j);
                } else {
                    prepare = last | (1 << j);
                }

                if (!used[prepare]) {
                    answer[i] = prepare;
                    used[prepare] = true;
                    break;
                }
            }
        }


        return answer;
    }
};