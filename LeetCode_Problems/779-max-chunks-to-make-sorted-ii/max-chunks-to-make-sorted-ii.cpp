class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> rightMin(n);
        rightMin[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(arr[i], rightMin[i + 1]);
        }

        int parts = 1;
        int leftMax = arr[0];

        for (int i = 0; i <= n - 2; i++) {
            leftMax = max(leftMax, arr[i]);
            if (leftMax <= rightMin[i + 1]) {
                parts++;
            }
        }

        return parts;
    }
};
