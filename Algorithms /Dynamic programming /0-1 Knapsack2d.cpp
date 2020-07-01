#include<bits/stdc++.h>

using namespace std ;

int val[] = {60 , 100,120} ; 
int w[] = {10, 20 , 30 } ;

int m = 50 ; 

int dp[2][1000] ; 


int main(){

  int prev = 0 , now = 1 ; 
  //  formula = max(dp[i-1][j] , dp[i-1][j-p] + val[i]) ; 

  for(int i=0; i <= 3 ;i++){

    for(int j = 0 ; j<= m ; j++){
      if(i ==0 || j ==0 )
        continue ; 

      dp[now][j] = dp[prev][j] ;
      if( j >= w[i-1] )
        dp[now][j] = max(dp[now][j], dp[prev][j - w[i-1] ] + val[i-1]) ; 

    }
    prev^=1 ; 
    now^=1;
  }

  cout<<dp[prev][m] ; 



}