class Solution {
public:
    string orderlyQueue(string S, int K) {
        const int N = S.size();
        
        if (K == 1) {
            string answer = S;
            for (int i = 0; i <= N; i++) {
                string $1, $2, temp;
                
                $1 = S.substr(0, i);
                $2 = S.substr(i, N - i);
                
                temp = $2 + $1;
                answer = min(answer, temp);
            }
            return answer;
        } else {
            sort(S.begin(), S.end());
            return S;
        }
    }
};
