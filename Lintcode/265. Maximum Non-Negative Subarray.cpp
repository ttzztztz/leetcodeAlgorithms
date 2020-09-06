class Solution {
public:
    /**
     * @param A: an integer array
     * @return: return maxium contiguous non-negative subarray sum
     */
    int maxNonNegativeSubArray(vector<int> &A) {
        // write your code here
        const int N = A.size();
        int answer = -99999999;
        int cur = 0;
        
        for (int i = 0; i < N; i++) {
            if (A[i] < 0) {
                cur = 0;
            } else {
                cur += A[i];
                answer = max(answer, cur);
            }
        }
        
        if (answer == -99999999) {
            return -1;
        }
        return answer;
    }
};
