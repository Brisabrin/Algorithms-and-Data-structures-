#include<bits/stdc++.h>

using namespace std ;

int n , m ; 

int arr[100][100] ; 

int sum[100][100] ; 

int main(){

  cin>> n >> m ; 

  for(int i=1;i <=n;i++){

    for(int j=1;j<=m;j++){
      cin >> arr[i][j] ; 

      sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1]  - sum[i-1][j-1] ; 
    }
  }

   for(int i=1;i <=n;i++){

    for(int j=1;j<=m;j++){

      cout<< sum[i][j] <<" " ;  
    }
    cout<<endl ; 
  }

}