class Solution {
public:
    /**
     * @param a: the list of salary
     * @param target: the target of the sum
     * @return: the cap it should be
     */
    int solve(const vector<int>& a, int mid) {
        int answer = 0;
        for (int salary : a) {
            if (salary <= mid) answer += mid;
            else answer += salary;
        }
        return answer;
    }
    int getCap(vector<int> &a, int target) {
        const int N = a.size();
        
        sort(a.begin(), a.end());
        int left = 0, right = max((int) a.back(), (target / N) + 1);
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            if (solve(a, mid) < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
