class Solution {
public:
void dfs(vector<vector<int>>& image,int i,int j,int newcolor,int orgcolor ) {
     int m = image.size();
        int n = image[0].size();
 if(i<0||j<0|| i>=m || j>=n|| image[i][j]!=orgcolor ||image[i][j]==newcolor) return ;
image[i][j]=newcolor;
dfs(image,i-1,j,newcolor,orgcolor);
dfs(image,i,j+1,newcolor,orgcolor);
dfs(image,i+1,j,newcolor,orgcolor);
dfs(image,i,j-1,newcolor,orgcolor);

 
}
        
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};