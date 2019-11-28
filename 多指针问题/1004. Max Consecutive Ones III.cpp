class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int answer = 0;
        const int N = A.size();

        int left = 0, right = 0, current = 0;
        while (right < N) {
            if (A[right] == 0) {
                current++;
            }

            while (current > K) {
                if (A[left] == 0) {
                    current--;
                }
                left++;
            }

            answer = max(answer, right - left + 1);
            right++;
        }


        return answer;
    }
};