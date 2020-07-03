//  lis nlogn() 
#include<bits/stdc++.h>


using namespace std ;

int n = 6 , k  ;  
int b[1000001] ; 
int a[] = { 7,5, 8 ,1 ,9, 2 } ;

int main(){

  for (int i=0 ; i<n;i++){
    int ind = lower_bound(b , b + k , a[i] ) - b ; 

    b[ind] = a[i] ; 

    k = max(k , ind + 1 ) ; 

  }

  cout<< k << endl ; 

}