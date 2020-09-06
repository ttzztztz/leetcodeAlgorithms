class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string cur, answer;
        for (int i = 1; i <= n; i++) cur.push_back(i);
        
        for (int i = 0; i < n; i++) {
            const int f = fact(n - i - 1);
            answer.push_back('0' + cur[k / f]);
            cur.erase(cur.begin() + (k / f));
            k %= f;
        }
        
        return answer;
    }
private:
    int fact(int n) {
        int answer = 1;
        for (int i = 2; i <= n; i++) answer *= i;
        return answer;
    }
};
