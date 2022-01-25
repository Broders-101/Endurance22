class Solution
{
public:
    void dfs(vector<int> &ans, vector<bool> &vis, vector<int> adj[], int node)
    {
        vis[node] = true;
        ans.push_back(node);

        for (auto it : adj[node])
        {
            if (vis[it])
                return;
            else
            {
                vis[it] = true;
                dfs(ans, vis, adj, it);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {

        vector<int> ans;
        vector<bool> vis(V, 0);
        dfs(ans, vis, adj, 0);

        return ans;
    }
};