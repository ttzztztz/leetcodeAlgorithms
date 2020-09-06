class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        const int N = arr1.size(), M = arr2.size();
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            bool find = false;
            for (int j = 0; j < M; j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    find = true;
                    break;
                }
            }
            
            if (!find) answer++;
        }
        return answer;
    }
};
