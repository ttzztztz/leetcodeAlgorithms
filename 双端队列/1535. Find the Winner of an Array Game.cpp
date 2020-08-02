class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        const int N = arr.size();
        k = min(k, N);
        
        deque<int> q(arr.begin(), arr.end());
        int win_cnt = 0, win_elem = q[0];
        while (win_cnt != k) {
            const int f = q[0];
            const int g = q[1];
            
            q.pop_front();
            q.pop_front();
            
            if (g > f) {
                q.push_back(f);
                q.push_front(g);
                
                win_cnt = 1;
                win_elem = g;
            } else {
                q.push_front(f);
                q.push_back(g);
                
                win_cnt++;
            }
        }
        
        if (win_cnt >= k) return win_elem;
        return -1;
    }
};