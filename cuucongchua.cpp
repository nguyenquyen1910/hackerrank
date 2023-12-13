#include<bits/stdc++.h>
using namespace std;
class SucManh{
    public:
        string tt;
        int hp,power;
};
int main(){
    SucManh a;
    string s;
    cin>>s>>s>>a.power;
    cin>>s>>s>>a.hp;
    cin>>a.tt;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string tmp;cin>>tmp;
        if(a.tt=="ALIVE"){
            if(tmp=="mushroom"){
                a.power-=2;
                a.hp-=15;
            }
            else if(tmp=="pea"){
                a.hp+=10;
                a.power+=2;
            }
            else if(tmp=="witch"){
                int k;cin>>k;
                if(k>=a.power){
                    a.tt="DEAD";
                    a.hp=0;
                    a.power=0;
                }
                else{
                    a.power+=5;
                }
            }
            else if(tmp=="soldier"){
                int k;cin>>k;
                if(k>=a.power){
                    a.tt="DEAD";
                    a.power=0;
                    a.hp=0;
                }
                else{
                    a.hp+=5;
                    a.power+=7;
                }
            }
        }
        cout << "POWER : " << a.power << endl;
        cout << "BLOOD : " << a.hp << endl;
        cout << a.tt << endl;
        cout << "--------------------\n";
    }
    return 0;
}