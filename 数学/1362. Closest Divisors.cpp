class Solution {
public:
    vector<int> solve(int num) {
        vector<int> answer;
        
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                const int l = i, r = num / i;
                if (answer.empty() || abs(answer[0] - answer[1]) > abs(l - r)) answer = {l, r};
            }
        }
        
        return answer;
    }
    vector<int> closestDivisors(int num) {
        vector<int> t1 = solve(num + 1);
        vector<int> t2 = solve(num + 2);
        
        if (t1.empty()) return t2;
        if (t2.empty()) return t1;
        
        if (abs(t1[0] - t1[1]) < abs(t2[0] - t2[1])) return t1;
        else return t2;
    }
};
