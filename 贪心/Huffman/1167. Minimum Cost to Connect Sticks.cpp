class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if (sticks.empty()) return 0;
        
        priority_queue<int, vector<int>, greater<>> heap;
        for (int stick : sticks) heap.push(stick);
        
        int ans = 0;
        while (heap.size() >= 2) {
            const int a = heap.top();
            heap.pop();
            const int b = heap.top();
            heap.pop();
            
            ans += a + b;
            heap.push(a + b);
        }
        return ans;
    }
};
