#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
const int N=200003;
char s1[N],s2[N];
struct node{
    int son[26];
    int fail;
    ll cishu;
}t1[N],t2[N];
int ent1,ent2;
ll pipei[N];
void insert1(char *p){
    int i,now=0,ch;
    for(i=0;p[i];i++){
        ch=p[i]-'a';
        if(!t1[now].son[ch]){
            t1[now].son[ch]=++ent1;
        }
        now=t1[now].son[ch];
    }
    t1[now].cishu++;
}
void insert2(char *p,int plen){
    int i,now=0,ch;
    for(i=plen-1;i>=0;i--){
        ch=p[i]-'a';
        if(!t2[now].son[ch]){
            t2[now].son[ch]=++ent2;
        }
        now=t2[now].son[ch];
    }
    t2[now].cishu++;
}
void getfail(node *t){
    int now,i;
    queue<int> q;
    for(i=0;i<26;i++){
        if(t[0].son[i]){
            q.push(t[0].son[i]);
        }
    }
    while(q.size()){
        now=q.front();
        q.pop();
        t[now].cishu+=t[t[now].fail].cishu;
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
void get(char *p,int plen){
    int i,now=0;
    for(i=plen-1;i>=0;i--){
        now=t2[now].son[p[i]-'a'];
        pipei[i]=t2[now].cishu;
    }
}
int main(){
    int n,i,now=0;
    ll ans=0;
    scanf("%s",s1);
    scanf("%d",&n);
    while(n--){
        scanf("%s",s2);
        insert1(s2);
        insert2(s2,strlen(s2));
    }
    getfail(t1);
    getfail(t2);
    get(s1,strlen(s1));
    for(i=0;s1[i];i++){
        now=t1[now].son[s1[i]-'a'];
        ans+=t1[now].cishu*pipei[i+1];
    }
    printf("%lld",ans);
    return 0;
}

