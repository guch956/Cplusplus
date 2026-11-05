#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1003;
struct {
    int son[3];
    int fail;
    int fenshu;    
}t[N];
int dp[2][N];
char s[N];
int ent;
void insert(char * s,int slen){
    int i,now=0,ch;
    for(i=0;i<slen;i++){
        ch=s[i]-'A';
        if(!t[now].son[ch]){
            t[now].son[ch]=++ent;
        }
        now = t[now].son[ch];
    }
    t[now].fenshu++;
}
void getfail(){
    int i,now;
    queue<int> q;
    for(i=0;i<3;i++){
        if(t[0].son[i]){q.push(t[0].son[i]);}
    }
    while(q.size()){
        now = q.front();
        q.pop();
        t[now].fenshu+=t[t[now].fail].fenshu;
        for(i=0;i<3;i++){
            if(t[now].son[i]){
                t[t[now].son[i]].fail=t[t[now].fail].son[i];
                q.push(t[now].son[i]);
            }
            else{
                t[now].son[i]=t[t[now].fail].son[i];
            }
        }
    }
}
void jisuan(int k){
    int i,j,fi=1,se=0;
    k++;
    while(k--){
        memset(dp[fi],0,sizeof(dp[fi]));
        for(i=0;i<=ent;i++){
            for(j=0;j<3;j++){
                dp[fi][i]=max(dp[fi][i],dp[se][t[i].son[j]]);
            }
        }
        for(i=0;i<=ent;i++){
            dp[fi][i]+=t[i].fenshu;
        }
        swap(fi,se);
    }
    printf("%d",dp[se][0]);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    while(n--){
        scanf("%s",s);
        insert(s,strlen(s));
    }
    getfail();
    jisuan(k);
    return 0;
}
