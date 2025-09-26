class Solution {
public:
    void Dijkstra(vector<vector<pair<int,int>>>&adj,vector<bool>&vis,vector<int>&dis,int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dis[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            int weight=pq.top().first;
            //cout<<node<<" ";
            pq.pop();
            if(dis[node]!=weight){
                continue;
            }
            for(auto u:adj[node]){
                if(dis[u.first]>weight+u.second){
                    dis[u.first]=weight+u.second;
                    pq.push({dis[u.first],u.first});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+10);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<bool>vis(n+10,false);
        vector<int>dis(n+10,INT_MAX);
        Dijkstra(adj,vis,dis,k);
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,dis[i]);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};