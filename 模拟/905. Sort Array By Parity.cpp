class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> odd, even;
        for (int i : A) {
            if (i % 2 == 1) odd.push_back(i);
            else even.push_back(i);
        }
        
        vector<int> answer;
        for (int i : even) answer.push_back(i);
        for (int i : odd) answer.push_back(i);
        return answer;
    }
};
