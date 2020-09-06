class Solution {
public:
    /**
     * @param x: the distance from cave A to cave A.
     * @param y: the distance from cave B to cave B.
     * @param z: the distance from cave B to exit C.
     * @return: return the expect distance to go out of the cave.
     */
    int expectDistance(int x, int y, int z) {
        // write your code here.
        return 2 * x + 4 + z + y;
    }
};
