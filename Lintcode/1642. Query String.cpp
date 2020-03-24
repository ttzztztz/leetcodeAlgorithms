class Solution {
public:
    /**
     * @param str: the string
     * @param n: the n
     * @return: yes or no
     */
    string queryString(string &str, int n) {
        vector<bool> visited(n + 1, false);
        int unvisited = n + 1;
        
        const int N = str.size();
        for (int i = N - 1; i >= 0; i--) {
            int current = 0;
            for (int j = 0; j <= 15 && i - j >= 0; j++) {
                if (str[i - j] == '1') current |= 1 << j;
                
                if (current <= n && !visited[current]) {
                    visited[current] = true;
                    unvisited--;
                }
            }
        }
        
        return unvisited == 0 ? "yes" : "no";
    }
};
