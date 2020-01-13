class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int answer = 0;
        unordered_map<int, int> cnt;
        int sum = 0;
        cnt[0] = 1;
        
        for (int a : A) {
            sum = (((sum + a) % K) + K) % K;
            
            answer += cnt[sum];
            cnt[sum]++;
        }
        
        return answer;
    }
};
