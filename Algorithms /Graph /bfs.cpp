#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 1000 ; 
vector<int> e[MAXN]; 

bool vis[MAXN] ; 
int n , m ; 

int main(){
  cin >> n >> m ; 

  for(int i=0;i<m;i++){
    int u , v  ; 
    cin >> u >> v ; 
    e[u].push_back({v}) ; 
    e[v].push_back({u}) ;

  }

  //  bfs 

  queue<int> q;  
  q.push(1) ; 

  while(!q.empty()){

    int u = q.front() ; 

    q.pop() ; 

    if( vis[u])
      continue ; 
    vis[u] = true ; 
    cout<< u << endl ; 
    
    for(int i=0;i<e[u].size();i++){
      int v = e[u][i] ; 

      if(!vis[v])
        q.push(v ); 

    }

  } 

}