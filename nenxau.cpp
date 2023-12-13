#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int cnt=1;
    for(int i=0;i<s.size();i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
        else{
            cout << s[i] << cnt;
            cnt=1;
        }
    }
    return 0;
}