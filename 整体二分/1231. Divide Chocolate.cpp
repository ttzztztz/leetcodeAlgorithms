class Solution {
public:
    /**
     * @param sweetness: an integer array
     * @param K: an integer
     * @return:  return the maximum total sweetness of the piece
     */
    int solve(const vector<int>& sweetness, int k) {
        int answer = 0, current = 0;
        
        for (int i : sweetness) {
            current += i;
            if (current >= k) {
                answer++;
                current = 0;
            }
        }
        
        return answer;
    }
    int maximizeSweetness(vector<int> &sweetness, int K) {
        const int N = sweetness.size();
        int left = *min_element(sweetness.begin(), sweetness.end()), right = 0;
        
        if (K >= N) return 0;
        K++;
        for (int i : sweetness) right += i;
        
        while (left <= right) {
            const int mid = (left + right) >> 1;
            if (solve(sweetness, mid) >= K) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left - 1;
    }
};
