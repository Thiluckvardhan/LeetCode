class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int x=n/2;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>i){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<x;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};