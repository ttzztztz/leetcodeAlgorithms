class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int MOD = 1e9+7;
        
        vector<pair<unsigned long long, unsigned long long>> people;
        for (int i = 0; i < n; i++) people.emplace_back(speed[i], efficiency[i]);
        sort(people.begin(), people.end(), [](const auto& $1, const auto& $2)->bool {
            return $1.second > $2.second;
        });
        priority_queue<unsigned long long, vector<unsigned long long>, greater<>> heap;
        unsigned long long heap_sum = 0, answer = 0;
        
        for (int i = 0; i < n; i++) {
            unsigned long long s, e;
            tie(s, e) = people[i];
            if (heap.size() < k) {
                heap.push(s);
                heap_sum += s;
            } else {
                if (heap.top() < s) {
                    unsigned long long tmp = heap.top();
                    heap.pop();
                    heap_sum -= tmp;
                    heap.push(s);
                    heap_sum += s;
                }
            }
            
            answer = max(answer, e * heap_sum);
        }
        
        answer %= MOD;
        return answer;
    }
};
