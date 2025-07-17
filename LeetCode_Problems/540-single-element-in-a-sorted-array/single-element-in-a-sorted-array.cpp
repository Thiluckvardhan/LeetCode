class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        if(n==0) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n]!=nums[n-1]) return nums[n];
        int low=1;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            else if(nums[mid]==nums[mid-1]){
                if(mid%2==0){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(mid%2==0){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return 0;
    }
};