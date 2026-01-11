class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> height(cols, 0);
        int maxarea = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            maxarea = max(maxarea, CalculateArea(height));
        }
        return maxarea;
    }

    int CalculateArea(vector<int>& height){
        stack<int> st;
        int maxarea = 0;
        height.push_back(0);

        for(int i = 0; i < height.size(); i++){
            while(!st.empty() && height[st.top()] > height[i]){
                int h = height[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxarea = max(maxarea, h * w);
            }
            st.push(i);
        }
        height.pop_back();
        return maxarea;
    }
};
