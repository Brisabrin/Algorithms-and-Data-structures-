#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 100 ; 
vector<int> e[MAXN] ;

int vis[MAXN] ; 
stack<int> s ;

int n , m ; 

void process(){

  int x = s.top() ; 
  s.pop() ; 

  vis[x] = 3 ; 

  while(s.size()){

    int y = s.top() ; 
    s.pop() ; 
    vis[y] = 3 ; 
    cout<< y <<" " ; 

    if( x == y )
      break ; 

  }
  cout<<endl ; 



}

void dfs( int u , int prev ){

  vis[u] = 2 ; 

  s.push(u) ; 

  for(int v : e[u]){

    if(vis[v] == 0 )
      dfs( v , u ) ; 

    else if(vis[v] == 2 && v !=prev)
      s.push(v) , process() ; 
  }

  if(vis[u] == 2 )
    vis[u] = 1 ; 

}
int main(){

  cin >> n >> m ;

  for(int i=0; i < m ; i++){

    int u ,v ; 
    cin >> u >> v ; 

    e[u].push_back(v) ; 
    e[v].push_back(u) ; 
  }

  dfs(1 , 0 ) ; 
}