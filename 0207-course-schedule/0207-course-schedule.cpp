class Solution {
public:

     bool dfs(int node, vector<vector<int>>& graph,
             vector<bool>& visited, vector<bool>& path) {

        visited[node] = true;
        path[node] = true;

        for(int neighb : graph[node]) {

            if(path[neighb])
                return true;

            if(!visited[neighb]) {
                if(dfs(neighb, graph, visited, path))
                    return true;
            }
        }

        path[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> graph(numCourses);

        for(auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        for(int i = 0; i < numCourses; i++) {

            if(!visited[i]) {
                if(dfs(i, graph, visited, path))
                    return false;
            }
        }

        return true;
    }
};