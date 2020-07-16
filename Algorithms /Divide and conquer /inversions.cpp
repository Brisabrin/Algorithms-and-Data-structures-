#include<bits/stdc++.h>


using namespace std ;

int n = 3 ; 
int a[] = { 1 ,3 , 2   } ;

int co = 0 ; 

void mergesort(int s , int mid , int t ){

  int n1 = mid - s + 1 ; 

  int n2 = t - mid ; 

  int l[n1] , r[n2] ; 

  for(int i = 0 ;  i < n1 ; i ++)  l[i] = a[s+i] ; 

  for(int i = 0 ; i < n2 ; i ++ ) r[i] = a[mid + i + 1 ] ; 

  int i = 0 , j = 0 , k = s   ; 

  vector<int> v ; 
  while( i < n1 && j < n2 ){

    if(l[i] <= r[j]){
      a[k] = l[i] , co += j   ; 
      for(int f = 0 ; f < v.size() ; f ++ ) 
        cout<< l[i] <<" " << v[f] <<endl ; 
      
      
      i ++ ; 
    }

    else 
      a[k] = r[j] , v.push_back(r[j])  , j ++ ; 

    k ++ ; 

  }

  while( i < n1 ){
    a[k] = l[i] , co += j ; 
    for(int f = 0 ; f <v.size() ; f ++ ){
      cout<< l[i] <<" " << v[f] <<endl ; 
    }

     i ++ , k ++ ; 
  }

  while( j < n2) 
    a[k] = r[j] , j ++ , k ++ ; 
    

}


void merge(int s , int t ){

  if(s < t ){

    int mid = ( s + t ) / 2 ; 

    merge(s , mid ) ; 

    merge( mid + 1 , t ) ; 

    mergesort( s , mid , t ) ; 

  }


}

int main(){

  merge(0 , n -1 ) ; 


  // for(int i = 0 ; i < n ; i ++)
  //   cout<< a[i] <<endl ; 

  cout<< co <<endl ; 


}