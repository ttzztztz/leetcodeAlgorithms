class Solution {
public:
    bool h[100005];
    vector<int> app[100005];
    
    int minNumberOperations(vector<int>& target) {
        int answer = 0;
        const int N = target.size();
        
        memset(h, 0, (N + 5) * sizeof(bool));
        h[0] = h[N + 1] = true;
        int intervalCount = 0;
        
        for (int i = 0; i < N; i++) {
            app[target[i]].push_back(i + 1);
        }
        
        int lst = 0;
        for (int num = 1; num <= 100000; num++) {
            const vector<int>& idx = app[num];
            if (idx.empty()) continue;
            
            answer += (num - lst) * (intervalCount + 1);
            for (int i : idx) {
                h[i] = true;

                if (h[i - 1] && h[i + 1]) intervalCount--;
                else if (!h[i - 1] && !h[i + 1]) intervalCount++;
            }
            lst = num;
        }
        
        return answer;
    }
};
