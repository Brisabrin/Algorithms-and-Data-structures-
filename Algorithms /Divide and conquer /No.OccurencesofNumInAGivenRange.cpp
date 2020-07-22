#include<bits/stdc++.h>

using namespace std ;

int n , q  ; 

map<int,vector<int> > mp ; 


int main(){


  scanf("%d%d",&n,&q) ; 

  for(int i = 1 ; i <= n ; i ++ ){
    int a ; 
    scanf("%d",&a) ; 
    mp[a].push_back(i) ; 

  }

  for(int i = 0 ; i < q ; i ++ ){

    int l , r , a ; 
    scanf("%d%d%d",&l, &r, &a) ; 
    vector<int> v  = mp[a] ; 

    int indL = lower_bound(v.begin(),v.end(), l) - v.begin() ; 
    int indR = upper_bound(v.begin() , v.end() , r ) - v.begin(); 

    cout<< indR - indL <<endl ;

  }


}