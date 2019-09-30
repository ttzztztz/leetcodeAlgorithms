class SegmentTreeNode {
public:
    int left, right, vote, candidate;
    SegmentTreeNode(): left(0), right(0), vote(0), candidate(0) {};
};

class Segment {
public:
    int vote, candidate;
    Segment(): vote(0), candidate(0) {};
    Segment(int v, int c): vote(v), candidate(c) {};
};

class MajorityChecker {
public:
    vector<vector<int>> adjacentList;
    SegmentTreeNode treeNode[100005];
    int L(int u) {
        return u << 1;
    }
    int R(int u) {
        return (u << 1) + 1;
    }
    int M(int u) {
        return (treeNode[u].left + treeNode[u].right) >> 1;
    }
    Segment mergeSegment(const Segment& $1, const Segment& $2) {
        Segment answer;
        if ($1.candidate == $2.candidate) {
            answer.candidate = $1.candidate;
            answer.vote = $1.vote + $2.vote;
        } else {
            if ($1.vote > $2.vote) {
                answer.candidate = $1.candidate;
                answer.vote = $1.vote - $2.vote;
            } else {
                answer.candidate = $2.candidate;
                answer.vote = $2.vote - $1.vote;
            }
        }
        return answer;
    }
    void pushUp(int u) {
        if (treeNode[L(u)].candidate == treeNode[R(u)].candidate) {
            treeNode[u].candidate = treeNode[L(u)].candidate;
            treeNode[u].vote = treeNode[L(u)].vote + treeNode[R(u)].vote;
        } else {
            if (treeNode[L(u)].vote > treeNode[R(u)].vote) {
                treeNode[u].candidate = treeNode[L(u)].candidate;
                treeNode[u].vote = treeNode[L(u)].vote - treeNode[R(u)].vote;
            } else {
                treeNode[u].candidate = treeNode[R(u)].candidate;
                treeNode[u].vote = treeNode[R(u)].vote - treeNode[L(u)].vote;
            }
        }
    }
    void build(const vector<int>& arr, int u, int left, int right) {
        treeNode[u].left = left;
        treeNode[u].right = right;
        treeNode[u].candidate = treeNode[u].vote = 0;
        if (left == right) {
            treeNode[u].vote = 1;
            treeNode[u].candidate = arr[left - 1];
            return;
        }

        int middle = (left + right) >> 1;
        if (left <= middle) {
            build(arr, L(u), left, middle);
        }
        if (middle < right) {
            build(arr, R(u), middle + 1, right);
        }
        pushUp(u);
    }
    Segment querySegment(int u, int left, int right) {
        if (left <= treeNode[u].left && treeNode[u].right <= right) {
            return Segment(treeNode[u].vote, treeNode[u].candidate);
        }

        Segment answer;
        int middle = M(u);
        if (left <= middle) {
            answer = mergeSegment(answer, querySegment(L(u), left, right));
        }
        if (middle < right) {
            answer = mergeSegment(answer, querySegment(R(u), left, right));
        }
        return answer;
    }
    MajorityChecker(vector<int>& arr) {
        adjacentList = vector<vector<int>>(20005, vector<int>());
        build(arr, 1, 1, arr.size());
        for (int i = 0; i < arr.size(); i++) {
            adjacentList[arr[i]].push_back(i);
        }
    }
    int querySum(int number, int left, int right) {
        const vector<int>& bucket = adjacentList[number];
        return std::upper_bound(bucket.begin(), bucket.end(), right) - std::lower_bound(bucket.begin(), bucket.end(), left);
    }
    int query(int left, int right, int threshold) {
        Segment totalSegment = querySegment(1, left + 1, right + 1);
        int appearCount = querySum(totalSegment.candidate, left, right);
        return appearCount >= threshold ? totalSegment.candidate : -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */