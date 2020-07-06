#include <bits/stdc++.h> 
using namespace std; 
const int MAXN = 100000; 
  

vector<int> e[MAXN] ; 
vector<int> cycles[MAXN]; 

int n , m ; 

void dfs_cycle(int u, int p, int color[], int mark[], int par[], int& cyclenumber) 
{ 
  
    if (color[u] == 2) { 
        return; 
    } 
  
    if (color[u] == 1) { 
  
        cyclenumber++; 
        int cur = p; 
        mark[cur] = cyclenumber; 
  
        while (cur != u) { 
            cur = par[cur]; 
            mark[cur] = cyclenumber; 
        } 
        return; 
    } 
    par[u] = p; 
  
    color[u] = 1; 
  
    for (int v : e[u]) { 
  
        if (v == par[u]) { 
            continue; 
        } 
        dfs_cycle(v, u, color, mark, par, cyclenumber); 
    } 
  
    color[u] = 2; 
} 

void printCycles(int edges, int mark[], int& cyclenumber) 
{ 
  

    for (int i = 1; i <= edges; i++) { 
        if (mark[i] != 0) 
            cycles[mark[i]].push_back(i); 
    } 
  
 
    for (int i = 1; i <= cyclenumber; i++) { 

        cout << "Cycle Number " << i << ": "; 
        for (int x : cycles[i]) 
            cout << x << " "; 
        cout << endl; 
    } 
} 

int main() 
{ 

  cin >> n >> m ; 

  for(int i=0 ; i<m;i++){
    int u ,v ; 
    cin >> u >> v ; 

    e[u].push_back(v) ; 
    e[v].push_back(u) ; 

  }

    int color[MAXN]; 
    int par[MAXN]; 
  
    int mark[MAXN]; 
    int cyclenumber = 0; 
    int edges = 13; 
  

    dfs_cycle(1, 0, color, mark, par, cyclenumber); 
  

    printCycles(edges, mark, cyclenumber); 
} 