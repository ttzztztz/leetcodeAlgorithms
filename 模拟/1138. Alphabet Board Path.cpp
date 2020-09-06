class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<pair<int, int>> position;
        for (int i = 0; i < 26; i++) {
            position.emplace_back(i / 5, i % 5);
        }
        
        string answer;
        int x = 0, y = 0;
        for (const char ch : target) {
            int nx, ny;
            tie(nx, ny) = position[ch - 'a'];
            
            int U = 0, D = 0, L = 0, R = 0;
            if (nx > x) {
                D = nx - x;
            } else if (nx < x) {
                U = x - nx;
            }
            
            if (y > ny) {
                L = y - ny;
            } else if (y < ny) {
                R = ny - y;
            }
            
            for (int i = 0; i < L; i++) answer.push_back('L');
            for (int i = 0; i < U; i++) answer.push_back('U');
            
            for (int i = 0; i < R; i++) answer.push_back('R');
            for (int i = 0; i < D; i++) answer.push_back('D');
            answer.push_back('!');
            x = nx, y = ny;
        }
        return answer;
    }
};
