#include<bits/stdc++.h>


using namespace std ;

int a[] = { 10 , 5 , 1 } ; 

int n ; 
int co = 0 ;  
int ind = 0 ; 

int main(){

  scanf("%d",&n) ; 
  while (n > 0 ){

    if(a[ind] > n )
      ind ++ ; 

    else {
      n -= a[ind] ;
      co ++ ;  
    }

  }
  cout<<co<<endl ; 
}