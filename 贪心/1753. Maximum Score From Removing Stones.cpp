class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int, vector<int>, less<>> heap;
        heap.push(a), heap.push(b), heap.push(c);
        
        int ans = 0;
        while (heap.size() >= 2) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            
            ans++;
            if (x - 1 >= 1) heap.push(x - 1);
            if (y - 1 >= 1) heap.push(y - 1);
        }
        return ans;
    }
};
