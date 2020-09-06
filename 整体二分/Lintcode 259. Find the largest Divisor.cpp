class Solution {
public:
    /**
     * @param A: the array.
     * @param k: the integer.
     * @return: the divisor satisfy the requirement.
     */
    int FindDivisor(vector<int> &A, int k) {
        long long left = A.size(), right = 0;
        for (int i : A) right += i;
        
        while (left <= right) {
            const int mid = (left + right) >> 1;
            if (judge(A, mid) < k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return right;
    }
private:
    long long judge(const vector<int>& A, long long d) {
        long long answer = 0;
        for (int i : A) {
            const long long f = i / d;
            if (i % d != 0) answer++;
            answer += f;
        }
        return answer;
    }
};
