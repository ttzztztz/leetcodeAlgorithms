class Solution {
public:
    double average(vector<int>& salary) {
        double answer = 0;
        const int N = salary.size();
        const int mx = *max_element(salary.begin(), salary.end());
        const int mi = *min_element(salary.begin(), salary.end());
        
        for (int i : salary) {
            if (i != mx && i != mi) answer += (double) i; 
        }
        
        return answer / (N - 2.0);
    }
};