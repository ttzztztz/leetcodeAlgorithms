class Solution {
public:
    /**
     * @param quality: an array
     * @param wage: an array
     * @param K: an integer
     * @return: the least amount of money needed to form a paid group
     */
    typedef pair<int, int> State;
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) {
        vector<State> workers;
        const int N = quality.size();
        for (int i = 0; i < N; i++) {
            workers.emplace_back(quality[i], wage[i]);
        }
        
        sort(workers.begin(), workers.end(), [](const auto& $1, const auto& $2)->bool {
           return $1.first * $2.second > $2.first * $1.second; 
        });
        
        double answer = numeric_limits<double>::max();
        priority_queue<int, vector<int>, less<>> heap;
        int heap_sum = 0;
        for (int i = 0; i < N; i++) {
            int qual, wag;
            tie(qual, wag) = workers[i];
            
            if (heap.size() < K) {
                heap.push(qual);
                heap_sum += qual;
            } else {
                heap_sum += qual;
                heap_sum -= heap.top();
                heap.pop();
                heap.push(qual);
            }
            
            if (heap.size() == K) {
                answer = min(answer, 1.0 * wag / qual * heap_sum);
            }
        }
        return answer;
    }
};
