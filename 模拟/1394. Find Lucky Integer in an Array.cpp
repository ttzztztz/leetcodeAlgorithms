class Solution {
public:
    int findLucky(vector<int>& arr) {
        const int N = arr.size();
        unordered_map<int, int> appear;
        for (int i : arr) appear[i]++;
        
        int answer = -1;
        for (auto& p : appear) {
            if (p.first != p.second) continue;
            if (p.first > answer) answer = p.first;
        }
        return answer;
    }
};
