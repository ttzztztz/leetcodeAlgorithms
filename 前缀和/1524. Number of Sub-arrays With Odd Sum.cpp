class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long answer = 0;
        const int mod = 1e9+7;
        
        const int N = arr.size();
        int odd = 0, even = 1, sum = 0;
        for (int i = 0; i <= N; i++) {
            if (sum % 2 == 1) { // odd
                answer += even;
                answer %= mod;
            } else { // even
                answer += odd;
                answer %= mod;
            }
            
            if (i < N) {
                sum += arr[i];
                if (sum % 2 == 1) odd++;
                else even++;
            }
        }
        
        return answer;
    }
};
