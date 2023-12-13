#include<bits/stdc++.h>
using namespace std;
int findpos(int n,int k){
    vector<int> v;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            while(n%i==0){
                v.push_back(i);
                n/=i;
            }
        }
    }
    if(n!=1) v.push_back(n);
    if(k<v.size()+1){
        return v[k-1];
    }
    return -1;
}
int main(){
    int n,k;cin>>n>>k;
    cout << findpos(n,k);
    return 0;
}