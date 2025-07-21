class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int bmade=nobou(arr,k,mid);
            if(bmade>=m){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
    int nobou(vector<int>arr,int k,int bday){
        int count=0;
        int prefixsum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=bday){
                prefixsum++;
                if(prefixsum>=k){
                    count++;
                    prefixsum=0;
                }
            }
            else{
                prefixsum=0;
            }
        }
        return count;
    }
};