class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const int N = bits.size();
        if (bits[N - 1] == 1) return false;
        
        f = vector<int>(N + 5, -1);
        return dfs(bits, 0);
    }
private:
    vector<int> f;
    bool dfs(const vector<int>& bits, int i) {
        if (i == bits.size() - 1) return true;
        if (i >= bits.size()) return false;
        
        if (f[i] != -1) return f[i];
        
        if (bits[i] == 0 && dfs(bits, i + 1)) return f[i] = true;
        if (bits[i] == 1 && dfs(bits, i + 2)) return f[i] = true;
        
        return f[i] = false;
    }
};
