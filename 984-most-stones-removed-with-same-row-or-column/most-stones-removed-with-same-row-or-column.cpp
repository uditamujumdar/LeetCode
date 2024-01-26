class DisJoint{
  public:
  vector<int>rank,parent,size;
  DisJoint(int n){
      rank.resize(n+1,0);
      parent.resize(n+1);
      size.resize(n+1);
      for(int i=0;i<=n;i++){
          parent[i]=i;
      }
      for(int i=0;i<=n;i++){
          size[i]=1;
      }
  }

  int findUPar(int node){
      if(parent[node]==node)
      return node;
      
      return parent[node]=findUPar(parent[node]);
  }

  void unionbyRank(int u,int v){
      int ulp_u=findUPar(u);
      int ulp_v=findUPar(v);
      
      if(ulp_u==ulp_v)return;
      
      if(rank[ulp_u]<rank[ulp_v]){
          parent[ulp_u]=ulp_v;
      }
      else if(rank[ulp_v]<rank[ulp_u]){
          parent[ulp_v]=ulp_u;
      }
      else{
           parent[ulp_v]=ulp_u;
           rank[ulp_u]++;
      }
  }

   void unionbySize(int u,int v){
      int ulp_u=findUPar(u);
      int ulp_v=findUPar(v);
      
      if(ulp_u==ulp_v)return;
      
      if(size[ulp_u]<size[ulp_v])
      {
          parent[ulp_u]=ulp_v;
          size[ulp_u]+=size[ulp_v];
      }
      else
      {
        parent[ulp_v]=ulp_u;
        size[ulp_v]+=size[ulp_u];  
      }
  }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0, maxcol=0;
        for(auto it: stones){
            maxrow=max(maxrow, it[0]);
            maxcol=max(maxcol, it[1]);
        }
        DisJoint ds(maxrow+maxcol+1);
        unordered_map<int, int>mp;
        for(auto it: stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;

            ds.unionbySize(noderow, nodecol);

            mp[noderow]=1;
            mp[nodecol]=1;
        }
        int cnt=0;
        for(auto it: mp){
            if(ds.findUPar(it.first)==it.first){
                cnt++;
            }
        }

        return n-cnt;
    }
};