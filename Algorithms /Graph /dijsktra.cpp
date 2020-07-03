#include<bits/stdc++.h>

using namespace std; 

struct edge{

  int v , w ; 

  bool operator<(const edge & other)const{
    return w > other.w ; 
  }
} ; 

priority_queue<edge> pq ; 
const int MAXN = 1000 ; 

vector<edge> e[MAXN] ; 
int n , m , s , t  ; 
int sol = 0 ; 

bool vis[MAXN] ; 

int main(){


  cin >> n >> m >> s >> t ; 

  for(int i=0;i<m;i++){

    int u , v , w ; 
    cin >> u >> v >> w ; 
    e[u].push_back({v,w}) ; 
    e[v].push_back({u,w}) ; 

  }

  pq.push({s,0}) ;

  vector<int> stp(MAXN) ; 

  fill( stp.begin() , stp.end(), -1u/4 ) ; 

  while(!pq.empty()){

    int u = pq.top().v ; 
    int cost = pq.top().w ; 

    pq.pop() ;

    if( vis[u] )  continue ; 
    vis[u] = true ; 

    stp[u] = cost ; 


    for(int i=0; i <e[u].size() ; i++){
      int v = e[u][i].v ; 
      int w = e[u][i].w ;

      if(stp[u] + w < stp[v])
        pq.push({v , cost + w }) ; 
    
    } 
  } 

  cout<< stp[t] <<endl ; 
}