class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        const int N = A.size();
        unordered_map<int, int> a;
        for (int i : A) a[i]++;
        
        for (const auto& p : a) if (p.second > 1) return p.first;
        return -1;
    }
};
