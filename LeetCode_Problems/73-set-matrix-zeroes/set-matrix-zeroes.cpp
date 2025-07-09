class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zero;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zero.push_back({i,j});
                }
            }
        }
        for(int i=0;i<zero.size();i++){
            int x=zero[i].first;
            int y=zero[i].second;
            for(int j=0;j<n;j++){
                if(matrix[x][j]!=0) matrix[x][j]=0;
            }
            for(int j=0;j<m;j++){
                if(matrix[j][y]!=0) matrix[j][y]=0;
            }
        }
    }
};