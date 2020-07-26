class Solution {
public:
    int countOdds(int low, int high) {
        const int x = high - low + 1;
        
        int answer = x / 2;
        if (low % 2 && high % 2) answer++;
        return answer;
    }
};
