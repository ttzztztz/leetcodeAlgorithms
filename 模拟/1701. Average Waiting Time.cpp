class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        const int n = customers.size();
        
        int last = -1;
        for (auto& customer : customers) {
            const int arrival = customer[0], time = customer[1];
            if (last <= arrival) {
                ans += time;
                last = arrival + time;
            } else {
                ans += (last - arrival) + time;
                last += time;
            }
        }
        
        return ans / (1.0 * n);
    }
};
