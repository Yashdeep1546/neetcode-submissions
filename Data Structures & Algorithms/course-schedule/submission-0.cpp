class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        vector<int> ind(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto v:arr) {
            adj[v[1]].push_back(v[0]);
            ind[v[0]]++;
        }
        queue<int> q;

        for(int i=0;i<numCourses;i++) if(ind[i]==0) q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int curr=q.front();q.pop();

            ans.push_back(curr);
            for(int nei:adj[curr]) {
                ind[nei]--;
                if(ind[nei]==0) q.push(nei);
            }
        }
        return numCourses==ans.size();
    }
};
