#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 1000 ; 
vector<int> e[MAXN] ; 
int n , m ; 

bool vis[MAXN] ; 

void dfs(int u ){
  if(vis[u])
    return ; 

  vis[u] = true ; 
  cout<< u <<endl ; 

  for(int i = 0 ;i<e[u].size();i++ ){

    int v = e[u][i] ; 
    if(!vis[v]) 
      dfs(v) ; 

  }
}


int main(){

  cin >> n >> m ; 

  for(int i=0 ;i<m ;i++ ){

    int u , v ; 
    cin >> u >> v ;

    e[u].push_back(v) ; 
    e[v].push_back(u) ; 
  }

  dfs(1) ; 

  
}