#include<bits/stdc++.h>
using namespace std;
long long F[505][505];
int main(){
    int n,m;cin>>n>>m;
    long long a[505][505];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    
    F[0][0]=a[0][0];
    for(int i=1;i<n;i++){
        F[i][0]=F[i-1][0]+a[i][0];
    }
    for(int j=1;j<m;j++){
        F[0][j]=F[0][j-1]+a[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            F[i][j]=max({F[i-1][j],F[i][j-1],F[i-1][j-1]})+a[i][j];
        }
    }
    cout << F[n-1][m-1];
    return 0;
}