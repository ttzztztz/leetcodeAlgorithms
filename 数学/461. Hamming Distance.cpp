class Solution {
public:
    int hammingDistance(int x, int y) {
        int answer = 0;
        int tmp = x ^ y;
        
        for (int i = 0; i <= 31; i++) {
            if (tmp & (1 << i)) answer++;
        }
        return answer;
    }
};
