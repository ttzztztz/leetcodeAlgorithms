class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long, vector<long long>, less<>> heap;
        for (int i : target) {
            sum += i;
            heap.push(i);
        }
        
        while (heap.top() != 1) {
            const long long top = heap.top();
            heap.pop();
            
            const long long next = 2 * top - sum;
            if (next <= 0) return false;
            
            heap.push(next);
            sum = top;
        }
        
        return true;
    }
};
