class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v =graph.size();
       vector<int>color(v,-1);
       queue<int>q;
       for(int i =0 ; i<v;i++) {
        if(color[i]!=-1) continue;
       
       color[i]=0;
       q.push(i);
       while(!q.empty()) {
        int node =q.front();
        q.pop();
        for(int j =0; j<graph[node].size();j++) {
            int neigh=graph[node][j];
            if(color[neigh]==-1) {
                color[neigh]=!color[node];
                q.push(neigh);

            }
            else {
                if(color[node]==color[neigh]) 
                return false;
            }
        }
       } 
       }
       return true; 
    }
};