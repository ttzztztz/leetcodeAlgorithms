class ZigzagIterator {
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        start[0] = v1.begin(), start[1] = v2.begin();
        end[0] = v1.end(), end[1] = v2.end();
    }

    /*
     * @return: An integer
     */
    int next() {
        int answer = 0;
        if (start[0] == end[0]) {
            answer = *start[1];
            start[1]++;
        } else if (start[1] == end[1]) {
            answer = *start[0];
            start[0]++;
        } else {
            answer = *start[ptr];
            start[ptr]++;
            ptr = (ptr + 1) % 2;
        }
        return answer;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return start[0] != end[0] || start[1] != end[1];
    }
private:
    vector<int>::iterator start[2], end[2];
    int ptr = 0;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
