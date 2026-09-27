class Solution {
public:

    void dfs(int i,vector<vector<int>>&adj,vector<int>&vis){
        if(vis[i]==1) return;
        vis[i]=1;

        for(int nei:adj[i]) {
            dfs(nei,adj,vis);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){ 
            adj[e[0]].push_back(e[1]);
             adj[e[1]].push_back(e[0]);
            
        }

        vector<int> vis(n,0);
        dfs(0,adj,vis);

        for(int i:vis) if(i==0) return false;
        return edges.size()==n-1;
    }
};
