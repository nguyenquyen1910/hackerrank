#include<bits/stdc++.h>
using namespace std;
class DoiBong{
    public:
        string id,na,name;
        int st,hs,ds;
        DoiBong(){
            id=na=name="";
            st=hs=ds=0;
        }
};
bool cmp(DoiBong a,DoiBong b){
    if(a.ds!=b.ds)
        return a.ds>b.ds;
    else if(a.ds==b.ds && a.hs!=b.hs)
        return a.hs>b.hs;
    return a.na<b.na;
}
int main(){
    DoiBong a[20];
    map<string,pair<pair<int,int>,int>> mp;
    for(int i=0;i<20;i++){
        cin>>a[i].id>>a[i].na;
        cin.ignore();
        getline(cin,a[i].name);
        cin>>a[i].st>>a[i].hs>>a[i].ds;
        string tmp;cin>>tmp;
    }
    cin.ignore();
    for(int i=0;i<10;i++){
        string s;getline(cin,s);
        int tmp;
        for(int j=0;j<s.size();j++){
            if(isdigit(s[j])){
                tmp=j;
                break;
            }
        }
        string team1="",team2="";
        for(int j=0;j<tmp-1;j++){
            team1+=s[j];
        }
        int x=0,y=0;
        while(s[tmp]!=' '){
            x=x*10+s[tmp]-'0';
            ++tmp;
        }
        tmp+=3;
        while(s[tmp]!=' '){
            y=y*10+s[tmp]-'0';
            ++tmp;
        }
        tmp+=1;
        while(tmp<s.size()){
            team2+=s[tmp];
            ++tmp;
        }
        mp[team1].first.first+=1;
        mp[team2].first.first+=1;
        mp[team1].first.second+=(x-y);
        mp[team2].first.second+=(y-x);
        if(x>y){
            mp[team1].second+=3;
        }
        else if(x==y){
            mp[team1].second+=1;
            mp[team2].second+=1;
        }
        else mp[team2].second+=3;
    }
    for(int i=0;i<20;i++){
        a[i].st+=mp[a[i].name].first.first;
        a[i].hs+=mp[a[i].name].first.second;
        a[i].ds+=mp[a[i].name].second;
    }
    sort(a,a+20,cmp);
    for(int i=0;i<20;i++){
        cout << "#" << i+1 << " " << a[i].na << " " << a[i].name << " " << a[i].st << " ";
        cout << a[i].hs << " " << a[i].ds << endl;
        cout << "------------------\n";
    }
    return 0;
}
