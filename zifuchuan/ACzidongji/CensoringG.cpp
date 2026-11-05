#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100003;
struct {
    int son[26];
    int fail;
    bool isend;
    int len;
}t[N];
int ent=0;
char str[N],p[N];
int zhan[N],pipei[N];
void insert(char * s,int slen){
    int i,now=0,ch;
    for(i=0;i<slen;i++){
        ch = s[i]-'a';
        if(!t[now].son[ch]){
            t[now].son[ch]=++ent;
            t[ent].len=t[now].len+1;
        }
        now = t[now].son[ch];
    }
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
        for(i=0;i<26;i++){
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
void query(char * s,int slen){
    int i,top=0,now=0;
    for(i=0;i<slen;i++){
        now = t[now].son[s[i]-'a'];
        zhan[++top]=i;
        if(t[now].isend){
            top = top-t[now].len;
            now = pipei[zhan[top]];
        }
        else{
            pipei[i]=now;
        }
    }
    for(i=1;i<=top;i++){
        printf("%c",s[zhan[i]]);
    }
}
int main(){
    int n;
    scanf("%s",str);
    scanf("%d",&n);
    while(n--){
        scanf("%s",p);
        insert(p,strlen(p));
    }
    getfail();
    query(str,strlen(str));
    return 0;
}