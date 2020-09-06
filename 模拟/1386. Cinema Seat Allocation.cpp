class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> reversed;
        const vector<int> v1 = {2,3,4,5}, v2 = {6,7,8,9}, v3 = {4,5,6,7};
        
        for (const auto& p : reservedSeats) reversed[p[0]].push_back(p[1]);
        int answer = 2 * (n - reversed.size());
        for (auto& p : reversed) {
            vector<bool> visited(11, true);
            for (const auto& index : p.second) visited[index] = false;
            
            bool b1 = true, b2 = true, b3 = true;
            for (int i : v1) {
                if (!visited[i]) {
                    b1 = false;
                    break;
                }
            }
            for (int i : v2) {
                if (!visited[i]) {
                    b2 = false;
                    break;
                }
            }
            for (int i : v3) {
                if (!visited[i]) {
                    b3 = false;
                    break;
                }
            }
            
            if (b1 && b2) answer += 2;
            else if (b1 || b2 || b3) answer++;
        }
        return answer;
    }
};
