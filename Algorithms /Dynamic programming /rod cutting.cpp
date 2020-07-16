#include<bits/stdc++.h>


using namespace std ;

int l[] = {1,2,3,4,5,6,7,8} ; 

int price[] = {3,5,8,9,10,17,17,20} ; 

int dp[10] ; 

int n = 8 ; 


int main(){

  dp[1] = price[0]; 

  for(int i = 2 ; i <= n ; i ++){
    dp[i] = price[i-1] ; 
    for(int j = 1 ; j < i ; j ++ ){
      dp[i] = max(dp[i] , dp[j] + price[i-j-1] ); 
    }

  }
  cout<< dp[8]<<endl ; 

}