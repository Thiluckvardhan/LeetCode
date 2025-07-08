class Solution {
private:
    bool check(int i,vector<vector<int>>&adjls,vector<int>&color){
        int n=adjls.size();
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto it:adjls[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=!color[node];
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i,graph,color)==false) return false;
            }
        }
        return true;
    }
};