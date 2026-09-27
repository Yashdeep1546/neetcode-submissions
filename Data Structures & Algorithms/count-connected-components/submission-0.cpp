class Solution {
public:


    void dfs(int i, vector<vector<int>>&adj, vector<int>&vis){
        if(vis[i]) return;
        vis[i]=1;

        for(auto n:adj[i]) {
            dfs(n,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans=0;

        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                ans++;
                dfs(i,adj,vis);
            }
        }

        return ans;
    }
};
