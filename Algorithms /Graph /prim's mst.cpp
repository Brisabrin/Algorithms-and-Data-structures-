#include<bits/stdc++.h>

using namespace std ;

struct edge{

  int v , w ; 

  bool operator<(const edge & other)const{
    return w > other.w ; 
  }
} ; 

const int MAXN = 1000 ; 
bool vis[MAXN] ; 

vector<edge> e [MAXN] ; 
int n , m  ; 

int sum = 0 ; 

int main(){

  cin >> n >> m ; 

  for(int i=0;i<m;i++){
    int u , v , w ; 
    cin >> u >> v >> w ; 
    e[u].push_back({v,w}) ;
    e[v].push_back({u,w}) ; 
  }

  priority_queue<edge> pq ; 
  pq.push({1,0}) ; 

  while(!pq.empty()){
    int u = pq.top().v ; 
    int w = pq.top().w ; 
    
    pq.pop() ; 
    if( vis[u])
      continue ; 
    vis[u] = true ; 
    sum += w ; 

    for(int i=0;i<e[u].size();i++){
      int v = e[u][i].v ; 
      if( !vis[v])
        pq.push({v,e[u][i].w}) ; 

    }

  }
  cout<< sum<<endl ; 


}