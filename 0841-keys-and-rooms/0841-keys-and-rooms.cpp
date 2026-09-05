class Solution {
public:
void dfs(vector<vector<int>> &rooms,int node,vector<int> &visited) {
    visited[node]=true;
    for(int i =0;i<rooms[node].size();i++) {
        int neigh =rooms[node][i];
        if(!visited[neigh]) {
            dfs(rooms,neigh,visited);
        }
    }

}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n =rooms.size();
        vector<int>visited(n,false);
        dfs(rooms,0,visited);
        for(int i =0; i<n;i++) {
            if(!visited[i]) {
                return false;
            }
        }
        return true;
    }
};