class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> state = {
            {'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}
        };
        unordered_map<char, int> currentState;
        int answer = 0, sze = 0;
        for (const auto& ch : croakOfFrogs) {
            const int s = state[ch];
            if (s == 0) sze++;
            if (s >= 1) {
                currentState[s - 1]--;
                if (currentState[s - 1] < 0) return -1;
            }
            if (s <= 3) {
                currentState[s]++;
            }
            if (s == 4) sze--;
            
            answer = max(answer, sze);
        }
        
        for (auto& p : currentState) if(p.second > 0) return -1;
        return answer;
    }
};
