#include<iostream>
#include<vector> 
#include<climits> 
using namespace std;
int f ( vector<int>& arr){
     int n= arr.size();
     vector<vector<int>> dp(1007 ,vector<int> (1007,-1));
     for (int len = 3;len <= n;len++){
          for (int i=0; len +i-1 <n; i++){
            int j= i+len -1;
            dp[i][j] = INT_MAX;
            for (int k=i+1; k< j; k++){
                dp [i][j] = min (dp[i][j], dp[i][k]+ dp[k][j]+ arr[i]*arr[j]);
            }
          }
     }
     return dp[0][n-1];
}
int main (){
    int n;
    cin>>n;
    vector<int> arr;
    for (int i=0;i<n;i++){
        int ele ;
        cin>>ele;
        arr.push_back (ele);
    }
    cout<< f(arr)<<endl;
}
