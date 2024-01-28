#include <iostream>
#include<vector> 
using namespace std ;
int f(string a, string b ,int i, int j){
    if (i==a.size()|| j==b.size()) return 0;
    if (a[i]!=b[j]) {
        return max (f(a,b, i,j+1), f(a,b,i+1, j));
    }
    else return 1 + f (a,b, i+1,j+1);
}
int main() {
    // I love Abhishek ji 
    // cout << "NamasKar Abhishek ji !" <<endl;
      string s1,s2;
      cin>>s1>>s2;
     // cout<<f(s1,s2,0,0)<<" "<<endl;
     vector<vector<int>> dp(207,vector<int> (205,0));
     for (int i= s1.size()-1; i>=0;i--){
        for (int j= s2.size()-1;j>=0;j--){
            if (s1[i]!=s2[j]) dp[i][j] = max (dp[i][j+1], dp[i+1][j]);
            else dp[i][j] = 1 + dp[i+1][j+1];
        }
     }
        cout<<dp[0][0]<<endl;
    return 0;
}