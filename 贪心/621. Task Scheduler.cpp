class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int N = tasks.size();
        if (n == 0) return N;
        
        unordered_map<char, int> occurrence;
        for (char task : tasks) occurrence[task]++;
        
        int answer = 0;
        priority_queue<int, vector<int>, less<>> heap;
        for (const auto p : occurrence) heap.push(p.second);
        
        while (!heap.empty()) {
            vector<int> next;
            
            for (int i = 0; i <= n; i++) {
                if (!heap.empty()) {
                    int top = heap.top();
                    heap.pop();

                    if (top >= 2) {
                        next.push_back(top - 1);
                    }
                }
                
                answer++;
                if (heap.empty() && next.empty()) break;
            }
            
            for (int i : next) heap.push(i);
        }
        
        return answer;
    }
};
