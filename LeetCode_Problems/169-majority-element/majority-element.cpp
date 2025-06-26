class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>map;
        int res=-1;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        int max=INT_MIN;
        for(auto it:map){
            if(max<it.second)
            {
                max=it.second;
                res=it.first;
            }
        }
    return res;
    }
};