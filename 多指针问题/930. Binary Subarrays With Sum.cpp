class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        const int N = A.size();
        int answer = 0;

        int left1 = 0, left2 = 0, right = 0;
        int sum1 = 0, sum2 = 0;

        while (right < N) {
            sum1 += A[right], sum2 += A[right];

            while (left1 <= right && sum1 > S) {
                sum1 -= A[left1];
                left1++;
            }
            while (left2 <= right && sum2 >= S) {
                sum2 -= A[left2];
                left2++;
            }

            answer += left2 - left1;
            right++;
        }
        return answer;
    }
};