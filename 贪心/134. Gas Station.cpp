class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minValue = 999999, minIndex = 0;
        const int N = gas.size();
        
        int curr = 0;
        for (int i = 0; i < N; i++) {
            curr += gas[i] - cost[i];
            if (curr < minValue) {
                minValue = curr, minIndex = i;
            }
        }
        
        if (curr < 0) {
            return -1;
        } else {
            return (minIndex + 1) % N;
        }
    }
};
