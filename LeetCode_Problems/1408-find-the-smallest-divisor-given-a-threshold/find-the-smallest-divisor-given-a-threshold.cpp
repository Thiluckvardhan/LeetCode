class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int res=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool a=ispossible(nums,mid,threshold);
            if(a){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
    bool ispossible(vector<int>&nums,int mid,int check){
        int sum=0;
        for(auto it:nums){
            if(it%mid==0){
                sum+=it/mid;
            }
            else{
                sum+=it/mid +1;
            }
        }
        if(sum<=check){
            return true;
        }
        return false;
    }
};