class ZigzagIterator2 {
public:
    /*
    * @param vecs: a list of 1d vectors
    */
    ZigzagIterator2(vector<vector<int>>& vecs) {
        this->N = vecs.size();
        for (vector<int>& v : vecs) {
            start.push_back(v.begin());
            end.push_back(v.end());
        }
    }

    /*
     * @return: An integer
     */
    int next() {
        int answer = 0;
        while (start[ptr] == end[ptr]) {
            ptr = (ptr + 1) % N;
        }
        answer = *start[ptr];
        start[ptr]++;
        ptr = (ptr + 1) % N;
        return answer;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        for (int i = 0; i < N; i++) {
            if (start[i] != end[i]) return true;
        }
        return false;
    }
private:
    vector<vector<int>::iterator> start, end;
    int ptr = 0, N = 0;
};

/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
