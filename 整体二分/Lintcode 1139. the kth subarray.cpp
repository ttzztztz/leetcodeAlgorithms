class Solution {
public:
    /**
     * @param a: an array
     * @param k: the kth
     * @return: return the kth subarray
     */
    long long thekthSubarray(vector<int> &a, long long k) {
        long long left = *min_element(a.begin(), a.end()), right = 0;
        for (int i : a) right += (long long) i;
        
        while (left <= right) {
            const long long mid = (left + right) >> 1;
            
            if (solve(a, mid) < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
private:
    long long solve(const vector<int> &a, long long s) {
        long long answer = 0;
        
        for (long long left = 0, right = 0, sum = 0; right < a.size(); right++) {
            
            sum += a[right];
            while (sum > s) {
                sum -= a[left];
                left++;
            }
            
            answer += right - left + 1;
        }
        return answer;
    }
};
