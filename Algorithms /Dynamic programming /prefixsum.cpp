#include<bits/stdc++.h>

using namespace std; 


const int MAXN  = 1000 ; 
int sum[MAXN] ; 

int n ; 

int main(){

  scanf("%d",&n) ; 

  for(int i=1;i<=n;i++){
    int d;  
    scanf("%d",&d) ; 
    if( i == 1 )
      sum[i] = d ; 
    else 
      sum[i] = sum[i-1] + d;
  }

  for(int i=0;i<n;i++){
    for(int j= i + 1 ;j<=n ; j++){
      cout<< i <<' '<<j <<' '<<sum[j] - sum[i] <<endl ; 

    }
  }


}