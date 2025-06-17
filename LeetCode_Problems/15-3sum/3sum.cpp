class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<size-2;i++){
            int start=i+1;
            int end=size-1;
            while(start<end){
                int sum=nums[start]+nums[end]+nums[i];
                if(sum==0){
                    res.insert({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                }
                else if(sum>0){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};