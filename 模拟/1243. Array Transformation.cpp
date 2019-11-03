class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        const int N = arr.size();
        while (true) {
            vector<int> tempArr = arr;
            bool changed = false;
            for (int i = 1; i < N - 1; i++) {
                if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    tempArr[i]--;
                    changed = true;
                }
                if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                    tempArr[i]++;
                    changed = true;
                }
            }
            arr = tempArr;
            if (!changed) {
                break;
            }
        }
        return arr;
    }
};