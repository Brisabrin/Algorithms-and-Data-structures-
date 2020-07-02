#include<bits/stdc++.h>

using namespace std ;

int n = 5 ;

const int MAXN = 100000 + 5 ; 
int arr[] = {5,3,1,7,2} ; 

void mergesort(int s , int mid , int t ){

  int n1 = mid - s + 1 ; 
  int n2 = t - mid ; 

  int l[n1] , r[n2] ;
  int k , i = 0 , j = 0 ; 

  while( i < n1 ){
    l[i] = arr[s + i ] ; 
    i ++ ; 
  }

  while(j < n2 ){
    r[j] = arr[mid + j + 1 ] ; 
    j++ ; 
  }
  i=0 , j=0 ; 
  k = s ; 

  while(i < n1 && j <n2 ){

    if(l[i] < r[j]){ 
      arr[k] = l[i] , i++ ; 
    }
    else 
       arr[k] = r[j] , j++ ; 

    k ++ ; 
  }

  while(i<n1){
    arr[k] = l[i] ; 
    k ++ , i++ ; 
  }

  while(j <n2){
    arr[k] = r[j] ; 
    k++ , j++ ; 
  }
}
void merge(int s , int t ){
  
  if(s < t ){
    int mid = (s+t)/ 2 ; 

    merge(s, mid ); 
    merge(mid + 1 , t ) ;
    mergesort(s ,mid , t ) ; 
  }
  return ;
}

int main(){

  merge(0 , n-1 ) ; 

  for(int i=0;i<n;i++){
    
    cout<< arr[i] <<endl ; 
  }


}