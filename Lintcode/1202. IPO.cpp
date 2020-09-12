class Solution {
public:
    /**
     * @param k: an integer
     * @param W: an integer
     * @param Profits: an array
     * @param Capital: an array
     * @return: final maximized capital
     */
    int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital) {
        typedef pair<int, int> PII;
        vector<PII> v;
        const int n = Profits.size();
        for (int i = 0; i < n; i++) {
            v.emplace_back(Capital[i], Profits[i]);
        }
        sort(v.begin(), v.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1.first < $2.first;
        });
        
        priority_queue<int, vector<int>, less<>> heap;
        for (int ptr = 0; k && ptr < n; ) {
            while (ptr < n && v[ptr].first <= W) {
                heap.push(v[ptr++].second);
            }
            
            if (heap.empty()) break;
            W += heap.top();
            heap.pop();
            k--;
        }
        
        while (k && !heap.empty()) {
            k--;
            W += heap.top();
            heap.pop();
        }
        return W;
    }
};
