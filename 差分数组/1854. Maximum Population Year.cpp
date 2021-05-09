class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int, int> diff;
        for (auto& log : logs) {
            diff[log[0]]++;
            diff[log[1]]--;
        }
        
        int year = 0, population = -1, cur = 0;
        for (int i = 1950; i <= 2050; i++) {
            cur += diff[i];
            if (cur > population) {
                population = cur;
                year = i;
            }
        }
        return year;
    }
};
