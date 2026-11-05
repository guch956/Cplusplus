#include<iostream>
using namespace std;
int n;
int main(){
    int a,b,c,d,e,q;
    cin>>q;
    while(q>0){
    cin>>n;
    q--;
    if(n==1){
        cin>>a;
        cout<<"Huoyu"<<endl<<0<<endl;
    }
    if(n==2){
        cin>>a>>b;
        cout<<"Shuiniao"<<endl;
    }
    if(n==3){
        cin>>a>>b>>c;
        if((a^b)==c){
            cout<<"Huoyu"<<endl<<1<<endl;
            cout<<1<<' '<<2<<' '<<3<<endl;
        }
    }
    if(n==4){
        cin>>a>>b>>c>>d;
        if((a^d)==b){
            cout<<"Huoyu"<<endl<<1<<endl;
            cout<<1<<' '<<2<<' '<<4<<endl;
        }
        else if((a^d)==c){
            cout<<"Huoyu"<<endl<<1<<endl;
            cout<<1<<' '<<3<<' '<<4<<endl;
        }
        else{
            cout<<"Shuiniao"<<endl;
        }
    }
    }
    return 0;
}