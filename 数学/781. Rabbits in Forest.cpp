class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int answer = 0;
        
        unordered_map<int, int> colorMap;
        for (int ans : answers) {
            if (ans == 0) answer++;
            else colorMap[ans]++;
        }
        
        for (auto p : colorMap) {
            int number, count;
            tie(number, count) = p;
            
            answer += count + ((-count % (number + 1)) + (number + 1)) % (number + 1);
        }
        
        return answer;
    }
};
