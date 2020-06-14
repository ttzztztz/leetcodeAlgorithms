class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        n = bloomDay.size();
        if (m * k > n) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end()), right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left <= right) {
            const int mid = (left + right) >> 1;
            if (judge(bloomDay, k, mid) < m) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
private:
    int n;
    int judge(vector<int>& day, int k, int d) {
        int adjacent = 0, answer = 0;
        for (int i : day) {
            if (i <= d) {
                adjacent++;
            } else{
                adjacent = 0;
            }
            
            if (adjacent == k) {
                answer++;
                adjacent = 0;
            }
        }
        return answer;
    }
};
