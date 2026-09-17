class Solution {
public:
bool valid(int i,int j,int n,int m) {
    return i>=0 && i<n &&j>=0 && j<m;
}
    void solve(vector<vector<char>>& board) {
        int n =board.size();
        int m =board[0].size();
        queue<pair<int,int>>q;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        for(int i =1 ; i<n-1; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = 'T';
                q.push({i, 0});
            }

            if(board[i][m-1] == 'O') {
                board[i][m-1] = 'T';
                q.push({i, m-1});
            }
        }

        // Top and bottom boundary
        for(int j = 0; j < m; j++) {

            if(board[0][j] == 'O') {
                board[0][j] = 'T';
                q.push({0, j});
            }

            if(board[n-1][j] == 'O') {
                board[n-1][j] = 'T';
                q.push({n-1, j});
            }
        }

        // BFS
        while(!q.empty()) {

            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for(int k = 0; k < 4; k++) {

                int ni = i + row[k];
                int nj = j + col[k];

                if(valid(ni, nj, n, m) &&
                   board[ni][nj] == 'O') {

                    board[ni][nj] = 'T';

                    q.push({ni, nj});
                }
            }
        }

        // Convert remaining O -> X
        // Convert T -> O
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        
        }

        
    }
};