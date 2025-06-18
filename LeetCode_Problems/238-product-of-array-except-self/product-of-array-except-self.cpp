class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        vector<int>prefixp(n,1);
        vector<int>suffixp(n,1);
        for(int index=n-2;index>=0;index--){
            suffixp[index]=suffixp[index+1]*nums[index+1];
        }
        for(int index=1;index<n;index++){
            prefixp[index]=prefixp[index-1]*nums[index-1];
        }
        for(int index=0;index<n;index++){
            res[index]=prefixp[index]*suffixp[index]; 
        }
        return res;
    }
};