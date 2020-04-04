class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited{n};
        while (n != 1) {
            n = calc(n);
            if (visited.count(n)) return false;
            visited.insert(n);
        }
        return true;
    }
private:
    int calc(int n) {
        int answer = 0;
        while (n) {
            const int d = n % 10;
            answer += d * d;
            n /= 10;
        }
        return answer;
    }
};
