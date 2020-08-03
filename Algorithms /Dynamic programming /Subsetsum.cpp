#include<bits/stdc++.h>


using namespace std ;

int n = 4  ;

bool  dp[100][100] ; 

int w[] = {5,10,9,4} ; 

int val = 6 ;

int main(){


  for(int i = 0 ; i <= n ; i++){

    for(int j = 0 ; j <= val ; j++ ) {

      if( i == 0 )
        dp[i][j] = false ; 

      else if( j == 0 )
        dp[i][j] = true ; 

      else{

        if( j >= w[i-1] )
          dp[i][j] = dp[i-1][j] || dp[i][j-w[i-1]] ; 
        else 
          dp[i][j] = dp[i-1][j] ; 

      }
    }

  }

  if(dp[n][val])
    cout<<"YES"<<endl ; 

  else 
    cout<<"NO" <<endl ; 

}