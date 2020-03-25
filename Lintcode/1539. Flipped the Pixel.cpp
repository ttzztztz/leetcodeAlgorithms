class Solution {
public:
    /**
     * @param Byte: 
     * @return: return the answer after flipped
     */
    vector<vector<int>> flippedByte(vector<vector<int>> &Byte) {
        for (vector<int>& v : Byte) reverse(v.begin(), v.end());
        for (vector<int>& u : Byte) {
            for (int& v : u) {
                v = !v;
            }
        }
        return Byte;
    }
};
