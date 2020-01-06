class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n, 0), diffSum(n + 5, 0);
        
        for (const vector<int>& booking : bookings) {
            diffSum[booking[0]] += booking[2];
            diffSum[booking[1] + 1] -= booking[2];
        }
        
        int last = 0;
        for (int i = 0; i < n; i++) {
            answer[i] = last + diffSum[i + 1];
            last = answer[i];
        }
        return answer;
    }
};
