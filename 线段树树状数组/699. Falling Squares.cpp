class SegmentTreeNode {
public:
    int left, right;
    int max, lazyTag;

    SegmentTreeNode(): left(0), right(0), max(0), lazyTag(0) {};
};


class Solution {
public:
    SegmentTreeNode treeNode[10050];
    int L(int u) {
        return (u << 1);
    }
    int R(int u) {
        return (u << 1) + 1;
    }
    void pushUp(int u) {
        treeNode[u].max = std::max(treeNode[L(u)].max, treeNode[R(u)].max);
    }
    void build(int u, int left, int right) {
        treeNode[u].left = left;
        treeNode[u].right = right;

        if (left == right) {
            treeNode[u].max = 0;
            return;
        }

        int middle = (left + right) >> 1;
        build(L(u), left, middle);
        build(R(u), middle + 1, right);
        pushUp(u);
    }
    void pushDown(int u) {
        if (!treeNode[u].lazyTag) {
            return;
        }

        treeNode[L(u)].max = std::max(treeNode[L(u)].max, treeNode[u].lazyTag);
        treeNode[R(u)].max = std::max(treeNode[R(u)].max, treeNode[u].lazyTag);
        treeNode[L(u)].lazyTag = std::max(treeNode[L(u)].lazyTag, treeNode[u].lazyTag);
        treeNode[R(u)].lazyTag = std::max(treeNode[R(u)].lazyTag, treeNode[u].lazyTag);

        treeNode[u].lazyTag = 0;
    }
    void update(int u, int left, int right, int val) {
        if (left <= treeNode[u].left && treeNode[u].right <= right) {
            treeNode[u].max = std::max(treeNode[u].max, val);
            treeNode[u].lazyTag = std::max(treeNode[u].lazyTag, val);
            return;
        }

        pushDown(u);
        int middle = (treeNode[u].left + treeNode[u].right) >> 1;
        if (left <= middle) {
            update(L(u), left, right, val);
        }
        if (middle < right) {
            update(R(u), left, right, val);
        }
        pushUp(u);
    }
    int query(int u, int left, int right) {
        if (left <= treeNode[u].left && treeNode[u].right <= right) {
            return treeNode[u].max;
        }

        int answer = 0;
        pushDown(u);
        int middle = (treeNode[u].left + treeNode[u].right) >> 1;
        if (left <= middle) {
            answer = std::max(answer, query(L(u), left, right));
        }
        if (middle < right) {
            answer = std::max(answer, query(R(u), left, right));
        }
        return answer;
    }

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        // <-- unique
        vector<int> allNumbers;
        for (const vector<int>& position : positions) {
            allNumbers.push_back(position[0]);
            allNumbers.push_back(position[1]);
            allNumbers.push_back(position[0] + position[1] - 1);
        }
        std::sort(allNumbers.begin(), allNumbers.end());
        auto endIterator = std::unique(allNumbers.begin(), allNumbers.end());
        for (vector<int>& position : positions) {
            position.push_back(std::lower_bound(allNumbers.begin(), endIterator, position[0] + position[1] - 1) - allNumbers.begin());

            position[0] = std::lower_bound(allNumbers.begin(), endIterator, position[0]) - allNumbers.begin();
            position[1] = std::lower_bound(allNumbers.begin(), endIterator, position[1]) - allNumbers.begin();
        }
        // <-- segment tree
        build(1, 1, endIterator - allNumbers.begin() + 1);
        vector<int> answer;
        int totalHeight = 0;
        for (const vector<int>& position : positions) {
            int leftUnique = position[0], heightUnique = position[1], rightUnique = position[2];
            int height = allNumbers[heightUnique];

            int currentAnswer = query(1, leftUnique + 1, rightUnique + 1);
            totalHeight = std::max(currentAnswer + height, totalHeight);
            answer.push_back(totalHeight);

            update(1, leftUnique + 1, rightUnique + 1, currentAnswer + height);
        }
        return answer;
    }
};