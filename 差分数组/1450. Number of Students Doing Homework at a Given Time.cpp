class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        vector<int> f(1005, 0);
        for (int i : startTime) f[i]++;
        for (int i : endTime) f[i + 1]--;
        for (int i = 1; i <= 1000; i++) f[i] += f[i - 1];
        
        return f[queryTime];
    }
};
