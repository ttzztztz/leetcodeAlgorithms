class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        const int N = envelopes.size();
        if (N <= 1) return N;
        
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& $1, const pair<int, int>& $2)->bool {
            if ($1.first == $2.first) {
                return $1.second > $2.second;
            } else {
                return $1.first < $2.first;
            }
        });
        
        vector<int> stk;
        for (int i = 0; i < N; i++) {
            if (stk.empty() || stk.back() < envelopes[i].second) {
                stk.push_back(envelopes[i].second);
            } else {
                int left = 0, right = stk.size() - 1;
                while (left <= right) {
                    const int mid = (left + right) >> 1;
                    if (stk[mid] < envelopes[i].second) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                stk[left] = envelopes[i].second;
            }
        }
        return stk.size();
    }
};
