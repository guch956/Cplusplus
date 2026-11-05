#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100003;
struct {
    int son[4];
    int fail;
    int len;
    bool vis;
}t[N*100];
int ent;
char s[N*100],p[N];
int a[100];
int weizhi[N];
int insert(char * s,int slen){
    int i,now=0;
    for(i=0;i<slen;i++){
        if(!t[now].son[a[s[i]]]){
            t[now].son[a[s[i]]]=++ent;
            t[ent].len = t[now].len+1;
        }
        now = t[now].son[a[s[i]]];
    }
    return now;
}
void getfail(){
    queue<int> q;
    int i,now;
    for(i=0;i<4;i++){
        if(t[0].son[i]){
            q.push(t[0].son[i]);
        }
    }
    while(q.size()){
        now = q.front();
        q.pop();
        for(i=0;i<4;i++){
            if(t[now].son[i]){
                q.push(t[now].son[i]);
                t[t[now].son[i]].fail=t[t[now].fail].son[i];
            }
            else{
                t[now].son[i] = t[t[now].fail].son[i];
            }
        }
    }
}
void query(char * s,int slen){
    int now=0,i,tmp;
    queue<int> q;
    for(i=0;i<slen;i++){
        now = t[now].son[a[s[i]]];
        tmp = now;
        while(tmp && (!t[tmp].vis)){
            t[tmp].vis = 1;
            tmp = t[tmp].fail;
        }
    }
    q.push(0);
    while(q.size()){
        now = q.front();
        q.pop();
        if(!t[now].vis){
            t[now].len=0;
        }
        for(i=0;i<4;i++){
            if(t[t[now].son[i]].len>t[now].len){
                q.push(t[now].son[i]);
                if(t[now].vis && (!t[t[now].son[i]].vis)){
                    t[t[now].son[i]].len=t[now].len;
                    t[t[now].son[i]].vis=1;
                }
            }
        }
    }
}
int main(){
    int n,sl,i;
    a[69]=0;a[83]=1;a[87]=2;a[78]=3;
    scanf("%d %d",&sl,&n);
    scanf("%s",s);
    for(i=0;i<n;i++){
        scanf("%s",p);
        weizhi[i]=insert(p,strlen(p));
    }
    getfail();
    query(s,sl);
    for(i=0;i<n;i++){
        printf("%d\n",t[weizhi[i]].len);
    }
    return 0;
}