class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> all;
        const int N = Profits.size();
        for (int i = 0; i < N; i++) {
            all.emplace_back(Profits[i], Capital[i]);
        }
        sort(all.begin(), all.end(), [](const pair<int, int>& $1, const pair<int, int>& $2)->bool {
            return $1.second < $2.second;
        });
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> heap;
        k++;
        int index = -1;
        heap.emplace(0, 0);
        while (k > 0 && !heap.empty()) {
            int profit, capital;
            tie(profit, capital) = heap.top();
            heap.pop();
            k--;
            W += profit;
            
            while (index + 1 < N && all[index + 1].second <= W) {
                heap.push(all[index + 1]);
                index++;
            }
        }
        return W;    
    }
};
