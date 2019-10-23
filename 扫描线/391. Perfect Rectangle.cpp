class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        const int MAX = 0x7fffffff, MIN = 0xffffffff;
        set<pair<int, int>> pointSet;
        pair<int, int> b1 = std::make_pair(MAX, MAX), b2 = std::make_pair(MIN, MIN);

        int totalSquare = 0;
        for (const vector<int>& rectangle : rectangles) {
            b1.first = std::min(b1.first, rectangle[0]), b1.second = std::min(b1.second, rectangle[1]);
            b2.first = std::max(b2.first, rectangle[2]), b2.second = std::max(b2.second, rectangle[3]);

            totalSquare += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);

            if (pointSet.count(std::make_pair(rectangle[0], rectangle[1]))) {
                pointSet.erase(std::make_pair(rectangle[0], rectangle[1]));
            } else {
                pointSet.insert(std::make_pair(rectangle[0], rectangle[1]));
            }

            if (pointSet.count(std::make_pair(rectangle[2], rectangle[3]))) {
                pointSet.erase(std::make_pair(rectangle[2], rectangle[3]));
            } else {
                pointSet.insert(std::make_pair(rectangle[2], rectangle[3]));
            }

            if (pointSet.count(std::make_pair(rectangle[0], rectangle[3]))) {
                pointSet.erase(std::make_pair(rectangle[0], rectangle[3]));
            } else {
                pointSet.insert(std::make_pair(rectangle[0], rectangle[3]));
            }

            if (pointSet.count(std::make_pair(rectangle[2], rectangle[1]))) {
                pointSet.erase(std::make_pair(rectangle[2], rectangle[1]));
            } else {
                pointSet.insert(std::make_pair(rectangle[2], rectangle[1]));
            }
        }

        cout << totalSquare << endl;
        if ((b2.second - b1.second) * (b2.first - b1.first) != totalSquare) {
            return false;
        }

        if (pointSet.size() == 4 &&
            pointSet.count(std::make_pair(b1.first, b1.second)) &&
            pointSet.count(std::make_pair(b1.first, b2.second)) &&
            pointSet.count(std::make_pair(b2.first, b1.second)) &&
            pointSet.count(std::make_pair(b2.first, b2.second))
                ) {
            return true;
        } else {
            return false;
        }

    }
};