#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=200003;
struct {
    int son[26];
    int fail;
    int num;
}t[N];
int ent;
char s[N*10];
int weizhi[N];
int zhan[N];
int insert(char * s,int slen){
    int i,now=0,ch;
    for(i=0;i<slen;i++){
        ch = s[i]-'a';
        if(!t[now].son[ch]){
            t[now].son[ch] = ++ent;
        }
        now = t[now].son[ch];
    }
    return now;
}
void getfail(){
    int i,now,top=0;
    queue<int> q;
    for(i=0;i<26;i++){
        if(t[0].son[i]){
            q.push(t[0].son[i]);
        }
    }
    while(q.size()){
        now = q.front();
        q.pop();
        zhan[++top] = now;
        for(i=0;i<26;i++){
            if(t[now].son[i]){
                t[t[now].son[i]].fail = t[t[now].fail].son[i];
                q.push(t[now].son[i]);
            }
            else{
                t[now].son[i] = t[t[now].fail].son[i];
            }
        }
    }
}
void query(char * s,int slen){
    int i,now=0;
    for(i=0;i<slen;i++){
        now = t[now].son[s[i]-'a'];
        t[now].num++;
    }
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        weizhi[i] = insert(s,strlen(s));
    }
    getfail();
    scanf("%s",s);
    query(s,strlen(s));
    for(i=ent;i>=1;i--){
        t[t[zhan[i]].fail].num += t[zhan[i]].num;
    }
    for(i=0;i<n;i++){
        printf("%d\n",t[weizhi[i]].num);
    }
    return 0;
}