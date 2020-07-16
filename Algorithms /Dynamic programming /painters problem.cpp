#include<bits/stdc++.h>

using namespace std ;

int n ;
int k ; 
int arr[100] ; 
int dp[100][100] ; 
int sum[100] ; 


int main(){
  cin >> n >> k ; 

  for(int i = 1 ; i<= n ; i ++){
    cin >> arr[i] ; 
    sum[i] = sum[i-1] + arr[i] ; 
  }

  for(int i = 1 ; i <= n ; i ++){

    dp[1][i] = dp[1][i-1] + arr[i] ; 
  }
  

  for(int i = 2 ; i <= k ; i ++ ){

    dp[i][i] = max(dp[i-1][i-1] , arr[i]) ; 


    for(int j = i + 1  ; j <= n ; j ++ ){
      dp[i][j] = INT_MAX ; 

      for ( int st = i  ; st <= j ; st ++  ){
        dp[i][j] = min( dp[i][j] , max(dp[i-1][st-1] , sum[j] - sum[st-1 ]) ) ; 
      }
    }

  }

  cout<< dp[k][n] <<endl; 

}