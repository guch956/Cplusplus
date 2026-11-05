#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200003;
struct node{
    int weizhi;
    int id;
    int sta;
}p[N<<1];
bool bijiao(node & n1,node & n2){
    return n1.weizhi<n2.weizhi;
}
int q[N<<1],head,tail;
bool exist[N];
int shunxu[N],num;
int zhan[N],top;
int main(){
    int n,i,j;
    int fx=0;
    bool xing=1;
    scanf("%d",&n);
    head=1;
    for(i=1;i<=n;i++){
        scanf("%d %d",&p[i*2-1].weizhi,&p[i*2].weizhi);
        p[i*2-1].id=p[i*2].id=i;
        p[i*2-1].sta=1;
    }
    sort(p+1,p+n*2+1,bijiao);
    for(i=1;i<=2*n;i++){
        if(!exist[p[i].id]){
            exist[p[i].id]=1;
            q[++tail]=p[i].id;
            if(fx==0){
                fx=p[i].sta+1;
            }
            else{
                if(p[i].sta+1!=fx){xing=0;}
            }
        }
        else{
            if(q[head]!=p[i].id){xing=0;}
            zhan[++top]=q[head];
            head++;
            if(head>tail){
                if(fx==1){
                    for(j=1;j<=top;j++){
                        shunxu[++num]=zhan[j];
                    }
                }
                else{
                    for(j=top;j>=1;j--){
                        shunxu[++num]=zhan[j];
                    }
                }
                top=0;
                fx=0;
            }
        }
    }
    if(!xing){printf("No");}
    else{
        printf("Yes\n");
        for(i=1;i<=n;i++){
            printf("%d ",shunxu[i]);
        }
    }
    return 0;
}