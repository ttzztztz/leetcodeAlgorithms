class Solution {
public:
    /**
     * @param array: the input array
     * @param k: the sequence length
     * @return: if it is possible, return true, otherwise false
     */
    bool partitionArratIII(vector<int> &array, int k) {
        const int N = array.size();
        if (N % k) return false;
        
        unordered_map<int, int> appear;
        int _mx = 0;
        for (int i : array) {
            appear[i]++;
            _mx = max(_mx, appear[i]);
        }
        
        return _mx <= (N / k);
    }
};
