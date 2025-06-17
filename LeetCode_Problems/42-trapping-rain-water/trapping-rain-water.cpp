class Solution {
public:
    int trap(vector<int>& arr) {
        int maxwater=0;
        int n=arr.size();
        if(n<=2) return 0;
        int leftglobalmax=arr[0];
        int rightglobalmax=arr[n-1];
        int left=0;
        int right=n-1;
        while(left<=right){
            if(arr[left]>leftglobalmax) leftglobalmax=arr[left];
            if(arr[right]>rightglobalmax) rightglobalmax=arr[right];

            if(arr[left]<=arr[right]){
                int mint=min(leftglobalmax,rightglobalmax);
                maxwater+=mint-arr[left];
                left++;
            }
            else{
                int mint=min(leftglobalmax,rightglobalmax);
                maxwater+=mint-arr[right];
                right--;
            }
        }
        return maxwater;
    }
};