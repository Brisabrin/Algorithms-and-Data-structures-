#include<bits/stdc++.h>

using namespace std ;

struct edge{
  int u , v , w ; 

  bool operator<(const edge &other)const{
    return w < other.w ; 
  }
} ; 

const int MAXN  = 1000 ; 

edge e[MAXN] ;  // max = edge ; 
int n , m  ; 
int par[MAXN] ;


int findpar(int u ){
  if(u == par[u])
    return u ; 
  
  return findpar(par[u]) ; 
  
}

int sum = 0 ; 

int main(){

  cin >> n >> m ; 
  for(int i=1; i<=n;i++){
    par[i] = i ; 
  }

  for(int i=0;i<m;i++){
    int u , v , w ; 
    cin >> e[i].u >> e[i].v >> e[i].w ;
  }

  sort(e , e + m ) ; 

  for(int i=0;i<m;i++){
    int u = e[i].u ; 
    int v = e[i].v ; 
    int w = e[i].w ; 

    int paru = findpar(u) ; 
    int parv = findpar(v) ; 

    if(paru == parv){
      continue ; 
    }

    par[paru] = parv ; 
    sum += w ; 
    
  }
  cout<< sum <<endl; 

}