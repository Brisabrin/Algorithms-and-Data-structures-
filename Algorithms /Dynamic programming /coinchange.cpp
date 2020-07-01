#include<bits/stdc++.h>

using namespace std ;

int c[] = { 1, 3 ,4 } ; 
int n = 10 ; 

int dp[100] ; 

int main(){

  for(int i=1;i<=n;i++){
    dp[i] = INT_MAX; 

    for(int j=0;j<3;j++){
      if(c[j] <=i) 
        dp[i] = min(dp[i] , dp[i-c[j]] + 1 ) ; 
    }


  }

  cout<<dp[n] <<endl ;

}