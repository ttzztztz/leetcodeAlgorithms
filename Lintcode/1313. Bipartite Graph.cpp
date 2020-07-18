class Solution {
public:
    /**
     * @param graph: graph edge value
     * @return: return the minium length of graph
     */
    int getMiniumValue(vector<vector<int>> &graph) {
        // write your code here.
        N = graph.size();
        int answer = 99999999;
        for (int i = 0; i < (1 << N); i++) {
            int cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) cnt1++;
                else cnt2++;
            }
            if (cnt1 < 2 || cnt2 < 2) continue;
            answer = min(answer, solve(graph, i));
        }
        return answer;
    }
private:
    int N = 0;
    int solve(vector<vector<int>> &graph, int state) {
        vector<int> s1, s2;
        for (int i = 0; i < N; i++) {
            if (state & (1 << i)) s1.push_back(i);
            else s2.push_back(i);
        }
        
        int m1 = 0, m2 = 0;
        for (int i = 0; i < s1.size(); i++) {
            for (int j = i + 1; j < s1.size(); j++) {
                m1 = max(m1, graph[s1[i]][s1[j]]);
            }
        }
        
        for (int i = 0; i < s2.size(); i++) {
            for (int j = i + 1; j < s2.size(); j++) {
                m2 = max(m2, graph[s2[i]][s2[j]]);
            }
        }
        return max(m1, m2);
    }
};
