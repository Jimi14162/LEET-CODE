class Solution {
public:
    void floodfill(vector<vector<int>>&image1,int i,int j, int color1,int value)
    {
        if(i<0 || i>=image1.size() || j<0 || j>=image1[0].size() || image1[i][j] == color1 || image1[i][j]!=value)
        {
            return ;
        }
        image1[i][j]=color1;
        floodfill(image1,i+1,j,color1,value);
        floodfill(image1,i-1,j,color1,value);
        floodfill(image1,i,j+1,color1,value);
        floodfill(image1,i,j-1,color1,value);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x=image[sr][sc];
        floodfill(image,sr,sc,color,x);
        return image;
        
    }
};