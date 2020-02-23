class Solution {
public:
    vector<bool> visited, finalState;
    bool dfs(int u, int parent, const vector<int>& leftChild, const vector<int>& rightChild) {
        visited[u] = true;
        const int l = leftChild[u], r = rightChild[u];
        
        bool answer = true;
        if (l != -1) {
            if (visited[l] || l == parent) return false;
            answer = answer && dfs(l, u, leftChild, rightChild);
        }
        if (r != -1) {
            if (visited[r] || r == parent) return false;
            answer = answer && dfs(r, u, leftChild, rightChild);
        }
        return answer;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        visited = vector<bool>(n, false);
        finalState = vector<bool>(n, true);
        
        return dfs(0, -1, leftChild, rightChild) && visited == finalState;
    }
};
