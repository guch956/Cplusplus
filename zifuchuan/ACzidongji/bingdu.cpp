#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=30003;
struct {
    int son[2];
    int fail;
    bool isend;
    int vis;
}t[N];
char s[N];
int ent,ans;
void insert(char * s,int slen){
    int i,now=0,ch;
    for(i=0;i<slen;i++){
        ch = s[i]-'0';
        if(!t[now].son[ch]){
            t[now].son[ch]=++ent;
        }
        now = t[now].son[ch];
    }
    t[now].isend=1;
}
void getfail(){
    int i,now;
    queue<int> q;
    for(i=0;i<2;i++){
        if(t[0].son[i]){
            q.push(t[0].son[i]);
        }
    }
    while(q.size()){
        now = q.front();
        q.pop();
        if(t[t[now].fail].isend){
            t[now].isend=1;
        }
        for(i=0;i<2;i++){
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
void dfs(int s){
    int v;
    t[s].vis=1;
    for(int i=0;i<2;i++){
        v = t[s].son[i];
        if(!t[v].vis){
            if(!t[v].isend){
                dfs(v);
            }
        }
        else if(t[v].vis==1){
            ans=1;
        }
    }
    t[s].vis=2;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        insert(s,strlen(s));
    }
    getfail();
    dfs(0);
    if(ans){
        cout<<"TAK";
    }
    else{
        cout<<"NIE";
    }
    return 0;
}