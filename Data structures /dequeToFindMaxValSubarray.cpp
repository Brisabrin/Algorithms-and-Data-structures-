#include<bits/stdc++.h>

using namespace std ;

int n , k ; 
const int MAXN  = 100 ; 
int arr[MAXN] ; 

deque<int> dq ; 

int main(){

  scanf("%d%d",&n, &k )  ;

  for(int i = 1 ; i <=n ; i ++ ){
    scanf("%d",&arr[i])  ;
  }

  for(int i = 1 ; i <= n ; i ++ ){

    while(!dq.empty() && i - dq.front() + 1 > k)
      dq.pop_front() ; 


    while ( !dq.empty() && arr[i] >= arr[dq.front()]){
      dq.pop_front() ; 
    }
    
    dq.push_back(i) ; 
    
    if( i >= k )
      cout<< arr[dq.front()] <<endl ;

  }

}