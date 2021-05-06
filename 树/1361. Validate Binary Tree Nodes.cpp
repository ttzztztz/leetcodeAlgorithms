class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);
        visited = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (parent[leftChild[i]] != -1) return false;
                parent[leftChild[i]] = i;
            }
            
            if (rightChild[i] != -1) {
                if (parent[rightChild[i]] != -1) return false;
                parent[rightChild[i]] = i;
            }
        }
        
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) continue;
            if (root == -1) root = i;
            else return false;
        }
        const auto final_visited = vector<bool>(n, true);
        return dfs(root, leftChild, rightChild) && visited == final_visited;
    }
private:
    vector<bool> visited;
    bool dfs(int root, vector<int>& l, vector<int>& r) {
        if (root == -1) return true;
        if (visited[root]) return false;
        visited[root] = true;
        
        return dfs(l[root], l, r) && dfs(r[root], l, r);
    }
};