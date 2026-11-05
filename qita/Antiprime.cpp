#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
ll pri[10];
ll shu[230000][11];
struct node{
    ll * t;
    node(ll * t1){t = t1;}
    bool operator<(const node & a)const{
        return (*t)>(*a.t);
    }
};
void jisuan(ll * p){
    int i,j;
    p[0]=p[10]=1;
    for(i=1;i<=9;i++){
        p[10] = p[10]*(p[i]+1);
        for(j=1;j<=p[i];j++)p[0]*=pri[i];
    }
}
int main(){
    ll x,now=1,num=1,geshu;
    node u(shu[0]);
    int ent=0,i;
    priority_queue<node> q;
    shu[0][0]=1;
    shu[0][10]=1;
    pri[1]=2;pri[2]=3;pri[3]=5;
    pri[4]=7;pri[5]=11;pri[6]=13;
    pri[7]=17;pri[8]=19;pri[9]=23;
    q.push(u);
    scanf("%lld",&x);
    while(1){
        u = q.top();
        q.pop();
        if((*u.t)>x){break;}
        if((*u.t)<now){continue;}
        geshu=*(u.t+10);
        if((*u.t)>now && geshu<=num){continue;}
        now = *u.t;
        num = geshu;
        for(i=1;i<=9;i++){
            if(i>=2 && (*(u.t+i))==(*(u.t+i-1))){continue;}
            memcpy(shu[++ent],u.t,sizeof(shu[0]));
            shu[ent][i]++;
            jisuan(shu[ent]);
            q.push(shu[ent]);
        }
    }
    printf("%lld",now);
    return 0;
}