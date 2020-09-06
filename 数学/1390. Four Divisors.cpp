class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        
        for (int i = 0; i < N; i++) {
            vector<int> div = divisor(nums[i]);
            if (div.size() == 4) {
                for (int j : div) answer += j;
            }
        }
        
        return answer;
    }
private:
    vector<int> divisor(int i) {
        vector<int> answer;
        
        const int _ub = sqrt(i);
        for (int a = 1; a <= _ub; a++) {
            if (i % a == 0) {
                answer.push_back(a);
                if ((i / a) != a) answer.push_back(i / a);
            }
        }
        
        return answer;
    }
};
