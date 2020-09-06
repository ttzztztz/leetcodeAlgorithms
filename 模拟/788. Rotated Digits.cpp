class Solution {
public:
    int rotatedDigits(int N) {
        int answer = 0;
        for (int i = 1; i <= N; i++) {
            if (valid(i)) answer++;
        }
        return answer;
    }
private:
    bool valid(int x, bool ok = false) {
        if (x == 0) return ok;
        
        const int d = x % 10;
        if (d == 3 || d == 4 || d == 7) return false;
        if (d == 0 || d == 1 || d == 8) return valid(x / 10, ok);
        return valid(x / 10, true);
    }
};