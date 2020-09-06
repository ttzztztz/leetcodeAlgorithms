class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        while (n) {
            answer++;
            n -= lowbit(n);
        }
        return answer;
    }
private:
    uint32_t lowbit(uint32_t x) {
        return x&(-x);
    }
};