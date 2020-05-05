class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = x ^ y;
        int answer = 0;
        for (int i = 0; i < 31; i++) {
            if (d & (1 << i)) answer++;
        }
        return answer;
    }
};
