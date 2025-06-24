class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>jarray;
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==key)
            {
                jarray.push_back(i);
            }
        }
        int m=jarray.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int index=i-jarray[j];
                if(index<0) index=index*-1;
                if(index<=k)
                {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};