class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumIndex;
        sumIndex[0] = -1;

        int maxLen = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0) ? -1 : 1;

            if (sumIndex.find(sum) != sumIndex.end()) {
                maxLen = max(maxLen, i - sumIndex[sum]);
            } else {
                sumIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
