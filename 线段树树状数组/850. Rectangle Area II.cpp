class SegmentTreeNode {
public:
    int left, right, total, covered;
    SegmentTreeNode() : left(0), right(0), total(0), covered(0) {};
};

class Segment {
public:
    int left, right;
    long long height;
    int flag;
    Segment() : left(0), right(0), height(0), flag(0) {};
    Segment(int l, int r, int h, int f) : left(l), right(r), height(h), flag(f) {};
};

class Solution {
public:
    SegmentTreeNode treeNode[1005];
    const int MOD = 1000000007;
    vector<int> allX;

    int L(int u) {
        return u << 1;
    }

    int R(int u) {
        return (u << 1) + 1;
    }

    int M(int u) {
        return (treeNode[u].left + treeNode[u].right) >> 1;
    }

    void pushUp(int u) {
        if (treeNode[u].covered) {
            treeNode[u].total = (allX[treeNode[u].right] - allX[treeNode[u].left - 1]) % MOD;
        } else if (treeNode[u].left == treeNode[u].right) {
            treeNode[u].total = 0;
        } else {
            treeNode[u].total = (treeNode[L(u)].total % MOD + treeNode[R(u)].total % MOD) % MOD;
        }
    }

    void build(int u, int left, int right) {
        treeNode[u].left = left;
        treeNode[u].right = right;
        treeNode[u].total = 0;
        if (left == right) {
            return;
        }

        int middle = (left + right) >> 1;
        build(L(u), left, middle);
        build(R(u), middle + 1, right);
        pushUp(u);
    }

    void update(int u, int left, int right, int covered) {
        if (left <= treeNode[u].left && treeNode[u].right <= right) {
            treeNode[u].covered += covered;
            pushUp(u);
            return;
        }

        int middle = M(u);
        if (left <= middle) {
            update(L(u), left, right, covered);
        }
        if (middle < right) {
            update(R(u), left, right, covered);
        }
        pushUp(u);
    }

    long long rectangleArea(vector<vector<int>> &rectangles) {
        // <-- unique & preprocess
        for (const vector<int> &rectangle : rectangles) {
            allX.push_back(rectangle[0]);
            allX.push_back(rectangle[2]);
        }
        std::sort(allX.begin(), allX.end());
        auto endIterator = std::unique(allX.begin(), allX.end());
        vector<Segment> segmentList;
        for (vector<int> &rectangle : rectangles) {
            rectangle[0] = std::lower_bound(allX.begin(), endIterator, rectangle[0]) - allX.begin();
            rectangle[2] = std::lower_bound(allX.begin(), endIterator, rectangle[2]) - allX.begin();

            segmentList.emplace_back(rectangle[0], rectangle[2], rectangle[1], 1);
            segmentList.emplace_back(rectangle[0], rectangle[2], rectangle[3], -1);
        }
        sort(segmentList.begin(), segmentList.end(), [](const Segment &$1, const Segment &$2) -> bool {
            return $1.height < $2.height;
        });

        // <-- segment tree
        long long answer = 0L;
        build(1, 1, endIterator - allX.begin());
        for (int i = 0; i < segmentList.size(); i++) {
            update(1, segmentList[i].left + 1, segmentList[i].right, segmentList[i].flag);
            if (i != segmentList.size() - 1) {
                answer = (answer + (treeNode[1].total * (segmentList[i + 1].height - segmentList[i].height)) % MOD) % MOD;
            }
        }
        return answer;
    }
};