class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hashmap;
        for(int i=0;i<nums.size();i++)
        {
            hashmap[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int b=target-a;
            if(hashmap.find(b)!=hashmap.end() && i!=hashmap[b]){
                return {i,hashmap[b]};
                break;
            }
        }
        return {0,0};
    }
};