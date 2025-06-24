class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>nextgreatest=nextgreatfinder(height);
        vector<int>prevgreatest=prevgreatfinder(height);
        int totalwater=0;
        int n=height.size();
        if(n<2){
            return 0;
        }
        for(int i=1;i<n-1;i++){
            int water=min(nextgreatest[i],prevgreatest[i])-height[i];
            if(water>0){
                totalwater+=water;
            }
        }
        return totalwater;
    }
    vector<int>nextgreatfinder(vector<int> height){
        int n=height.size();
        vector<int>arr(n,-1);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            int num=height[i];
            while(!s.empty() && num>=s.top()){
                s.pop();
            }
            if(s.empty()){
                arr[i]=0;
                s.push(height[i]);
            }
            else{
                arr[i]=s.top();
            }
        }
        return arr;
    }
        vector<int>prevgreatfinder(vector<int> height){
        int n=height.size();
        vector<int>arr(n,-1);
        stack<int>s;
        for(int i=0;i<n;i++){
            int num=height[i];
            while(!s.empty() && num>=s.top()){
                s.pop();
            }
            if(s.empty()){
                arr[i]=-1;
                s.push(height[i]);
            }
            else{
                arr[i]=s.top();
            }
        }
        return arr;
    }
};