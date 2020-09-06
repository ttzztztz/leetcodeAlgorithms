class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, double>> workers;
        const int N = quality.size();
        for (int i = 0; i < N; i++) {
            workers.emplace_back(quality[i], wage[i]);
        }
        sort(workers.begin(), workers.end(), [](const pair<double, double>& $1, const pair<double, double>& $2)->bool {
            return ($1.second / $1.first) < ($2.second / $2.first);
        });
        
        double answer = std::numeric_limits<double>::max();
        priority_queue<double, vector<double>, less<>> heap;
        double sum = 0.0;
        for (int i = 0; i < N; i++) {
            heap.push(workers[i].first);
            sum += workers[i].first;
            
            if (heap.size() == K) {
                double qual = heap.top();
                heap.pop();
                
                answer = min(answer, sum * (workers[i].second / workers[i].first));
                sum -= qual;
            }
        }
        return answer;
    }
};
