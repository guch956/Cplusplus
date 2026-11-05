#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=6003;
const int P=10007;
struct {
    int son[26];
    int fail;
    int dp[2];
    bool isend;
}t[N];
int ent;
int ppower[N];
char s[N];
void insert(char * s,int slen){
    int i,now=0,ch;
    for(i=0;i<slen;i++){
        ch = s[i]-'A';
        if(!t[now].son[ch]){
            t[now].son[ch]=++ent;
        }
        now = t[now].son[ch];
    }
    t[now].dp[0]=1;
    t[now].isend=1;
}
void getfail(){
    int i,now;
    queue<int> q;
    for(i=0;i<26;i++){
        if(t[0].son[i]){
            q.push(t[0].son[i]);
        }
    }
    while(q.size()){
        now = q.front();
        q.pop();
        if(t[t[now].fail].isend){
            t[now].isend=1;
            t[now].dp[0]=1;
        }
        for(i=0;i<26;i++){
            if(t[now].son[i]){
                q.push(t[now].son[i]);
                t[t[now].son[i]].fail=t[t[now].fail].son[i];
            }
            else{
                t[now].son[i]=t[t[now].fail].son[i];
            }
        }
    }
}
int main(){
    int n,m,now=1,old=0,i,j,k;
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%s",s);
        insert(s,strlen(s));
    }
    getfail();
    ppower[0]=1;
    for(i=1;i<=m;i++){
        ppower[i]=(ppower[i-1]*26)%P;
    }
    for(k=1;k<=m;k++){
        for(i=0;i<=ent;i++){
            t[i].dp[now]=0;
            if(t[i].isend){
                t[i].dp[now]=ppower[k];
            }
            else{
                for(j=0;j<26;j++){
                    t[i].dp[now]+=t[t[i].son[j]].dp[old];
                }
                t[i].dp[now]%=P;
            }
        }
        swap(now,old);
    }
    printf("%d",t[0].dp[old]);
    return 0;
}