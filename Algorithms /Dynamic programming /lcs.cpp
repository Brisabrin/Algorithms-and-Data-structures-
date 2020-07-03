#include<bits/stdc++.h>

using namespace std; 

string s  , s2 ; 

int n  , n2 ; 

const int MAXN = 1000 ; 

int dp[MAXN][MAXN] ; 

int lcs(){

  
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n2;j++){
      if( i== 0 || j ==0 )
        continue ; 

      else if( s[i-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1 ; 

      else 
        dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ; 

    }
  }
  return dp[n][n2] ; 

}


int main(){

  cin >> s >> s2 ; 

  n = s.length() ; 
  n2 = s2.length() ; 

  cout<< lcs() ; 

}