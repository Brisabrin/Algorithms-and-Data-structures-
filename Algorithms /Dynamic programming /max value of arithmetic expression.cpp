//  matrix chain multiplication approach


#include<bits/stdc++.h>
using namespace std ;

long long int mini[30][30] ; 
long long int maxi[30][30] ; 

long long int calc(long long int  a,long long int b , char op ){
  if(op=='+')
    return a + b;  
  else if(op=='-')
    return a - b ;
  return a*b ; 


}

int main(){

  string s ; 
  cin>> s ; 
  vector<long long int> num ; 
  string tmp = ""; 
  for (int i=0;i<s.length();i++)
  {
    if(s[i] == '+' || s[i]=='-' || s[i]=='*')
    {
      num.push_back(stoll(tmp.c_str())); 
      tmp= "";
    }
    else 
    {
      tmp += s[i]; 
    }
  }
  num.push_back(stoll(tmp.c_str())); 

  for (int i=0;i<num.size();i++){
    maxi[i][i] = num[i]; 
    mini[i][i] = num[i]; 
    }

  for (int l=0;l<num.size()-1;l++)
  
    for (int i=0;i<num.size()-l-1;i++)
    {
      int j = i + l + 1; 
      long long int minval = LLONG_MAX;
      long long int maxval = LLONG_MIN ; 
      
      for (int k = i;k<j;k++)
      {
        long long int a = calc(mini[i][k],mini[k+1][j],s[2*k+1]) ;
        long long int b = calc(mini[i][k],maxi[k+1][j],s[2*k+1]) ;
        long long int c = calc(maxi[i][k],mini[k+1][j],s[2*k+1]); 
        long long int d = calc(maxi[i][k],maxi[k+1][j],s[2*k+1]); 

        minval  = min(minval, min(a,min(b,min(c,d)))) ; 
        maxval  = max(maxval, max(a,max(b,max(c,d)))) ; 

      }
      mini[i][j] = minval; 
      maxi[i][j] = maxval ; 
    }
  

  // for (int i=0;i<num.size();i++)
  // {
  //   for (int j=0;j<num.size();j++)
  //   {
  //     cout<< maxi[i][j]<<' '; 
  //   }
  //   cout<< endl; 
  // }
  cout<<maxi[0][num.size()-1]; 



}