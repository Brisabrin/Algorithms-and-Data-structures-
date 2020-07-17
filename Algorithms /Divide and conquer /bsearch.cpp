#include<bits/stdc++.h>

using namespace std ;


int n , st , en ; 
int mid  ;
int arr[100] ; 
int val ; 

int main(){


  scanf("%d",&n) ; 


  for(int i = 0 ; i < n ; i ++){
    scanf("%d",&arr[i]) ; 
  }

  cin >> val ; 

  sort( arr , arr + n ) ; 


  st = 0 , en = n - 1 ; 

  while( st < en  ) {
  
    mid = (st + en ) >> 1 ; 

    cout<<st <<" " <<mid <<' '<<en <<endl ; 

    if(arr[mid] > val )
      en = mid - 1 ; 
    
    else 
      st = mid + 1  ; 

  }

  if( arr[en] == val )
    cout<<"YES" <<endl ; 

  else 
    cout<<"NO" <<endl ; 




}