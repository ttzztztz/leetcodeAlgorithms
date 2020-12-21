class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if (A.empty()) return 0;

        int ans = *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end());
        const int n = A.size();
        
        typedef pair<int, int> PII;
        set<PII> all_numbers;
        for (int i = 0; i < n; i++) {
            all_numbers.emplace(A[i] + K, 1);
        }
        
        while (true) {
            auto [last_num, last_rest] = *all_numbers.rbegin();
            auto [first_num, first_rest] = *all_numbers.begin();
            ans = min(ans, last_num - first_num);

            if (last_rest == 0) break;
            all_numbers.erase(--all_numbers.end());
            all_numbers.emplace(last_num - 2 * K, last_rest - 1);
        }
        return ans;
    }
};
