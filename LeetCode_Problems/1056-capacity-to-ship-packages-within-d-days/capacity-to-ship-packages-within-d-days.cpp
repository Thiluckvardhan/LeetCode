class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i:weights){
            high+=i;
        }
        int res=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(weights,mid,days)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
    bool ispossible(vector<int>&weights,int mid,int days){
        int count=0;
        int sum=0;
        for(int weight : weights){
            sum+=weight;
            if(sum>mid){
                count++;
                sum=weight;
            }
            if(sum==mid){
                count++;
                sum=0;
            }
        }
        if(sum!=0)count++;
        if(count<=days){
            return true;
        }
        return false;
    }
};