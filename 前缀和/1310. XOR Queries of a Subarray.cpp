class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;
        const int N = arr.size();
        vector<int> prefixSum(N + 1, 0);
        
        for (int i = 1; i <= N; i++) {
            prefixSum[i] = prefixSum[i - 1] ^ arr[i - 1];
        }
        
        for (const vector<int>& query : queries) {
            answer.push_back(prefixSum[query[1] + 1] ^ prefixSum[query[0]]);
        }
        return answer;
    }
};
