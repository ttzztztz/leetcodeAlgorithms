class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<>> heap;
        for (int block : blocks) heap.push(block);
        
        while (heap.size() >= 2) {
            const int a = heap.top();
            heap.pop();
            const int b = heap.top();
            heap.pop();
            
            heap.push(max(a, b) + split);
        }
        return heap.top();
    }
};
