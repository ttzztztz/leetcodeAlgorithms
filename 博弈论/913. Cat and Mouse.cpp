class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        const int N = graph.size();
        f = vector<vector<vector<int>>>(2 * N + 5, vector<vector<int>>(N + 1, vector<int>(N + 1, -1)));
        return dfs(graph, 0, 1, 2);
    }
private:
    vector<vector<vector<int>>> f;
    const int Tie = 0, Mouse = 1, Cat = 2;
    
    int dfs(const vector<vector<int>>& graph, int all, int mouse, int cat) {
        const int N = graph.size();
        if (all == 2 * N) return Tie;
        if (mouse == 0) return Mouse;
        if (cat == mouse) return Cat;
        
        if (f[all][mouse][cat] != -1) return f[all][mouse][cat];
        
        int& memo = f[all][mouse][cat];
        if (all % 2 == 0) { // mouse
            bool haveTie = false;
            for (int v : graph[mouse]) {
                const int result = dfs(graph, all + 1, v, cat);
                if (result == Mouse) return memo = Mouse;
                else if (result == Tie) haveTie = true;
            }
            
            if (haveTie) return memo = Tie;
            else return memo = Cat;
        } else { // cat
            bool haveTie = false;
            for (int v : graph[cat]) {
                if (v == 0) continue;
                
                const int result = dfs(graph, all + 1, mouse, v);
                if (result == Cat) return memo = Cat;
                else if (result == Tie) haveTie = true;
            }
            
            if (haveTie) return memo = Tie;
            else return memo = Mouse;
        }
    }
};
