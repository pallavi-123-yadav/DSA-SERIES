class Solution {
public:
bool valid(int i ,int j ,int n,int m ) {
    if(i<0 || i>=n || j<0 || j>=m) {
        return false;
    }
    return true;
}
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m =grid[0].size();
        queue<pair<int,int>>q;
        int fresh =0;
        int time =0;
        for(int i =0; i<n;i++) {
            for(int j=0; j<m;j++) {
            if(grid[i][j]==2) {
                q.push({i,j});
            }
            if(grid[i][j]==1) {
                fresh++;
            }
            }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty() && fresh>0) {
            int size =q.size();
            time++;
            while(size--) {
                pair<int,int>p =q.front();
                q.pop();
                int r=p.first;
                int c =p.second;
                for(int k =0; k<4;k++) {
                    int nr= r+dx[k];
                    int nc =c+dy[k];
                    if(valid(nr,nc,n,m) && grid[nr][nc]==1 ) {
                        q.push({nr,nc});
                        grid[nr][nc]=2;
                        fresh --;

                        }
                        
                    }
                }
            }
        
        if(fresh>0) 
        return -1;
        return time;

        
    }
};