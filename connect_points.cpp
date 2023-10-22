// Min Cost to Connect All Paths:  https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        int n=points.size();
        // Min Pq =>{first-> dis, second-> index};
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(n,false),mini(n,INT_MAX);
        int ans=0;
        pq.emplace(0,0);
        while(!pq.empty()){
            int dis=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            if(!vis[idx]){
                vis[idx]=true;
                ans+=dis;
                for(int i=0;i<n;i++){
                    if(!vis[i]){ //previous vis or not [duplicate]
                        int dis_cnt=abs(points[i][0]-points[idx][0])+abs(points[i][1]-points[idx][1]);
                        if(dis_cnt<mini[i]){
                            mini[i]=dis_cnt;
                            pq.emplace(mini[i],i);
                        }
                    }
                }
            }   
        }
        return ans;
    }
};
