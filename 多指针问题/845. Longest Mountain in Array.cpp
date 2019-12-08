class Solution {
public:
    int longestMountain(vector<int>& A) {
        const int N = A.size();
        if (N < 3) {
            return 0;
        }

        int answer = 0, index = 0;
        while (index < N) {
            int end = index;
            while (end + 1 < N && A[end] < A[end + 1]) {
                end++;
            }

            if (index + 1 <= end && end + 1 < N) {
                while (end + 1 < N && A[end] > A[end + 1]) {
                    end++;
                }

                if (end - index + 1 >= 3) {
                    answer = max(answer, end - index + 1);
                }
            }

            index = max(index + 1, end);
        }

        return answer;
    }
};