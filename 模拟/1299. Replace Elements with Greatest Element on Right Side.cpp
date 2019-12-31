class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        const int N = arr.size();

        int maxNumber = arr[N - 1];
        arr[N - 1] = -1;
        for (int i = N - 2; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = maxNumber;
            maxNumber = max(maxNumber, temp);
        }

        return arr;
    }
};