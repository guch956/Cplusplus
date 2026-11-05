#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=300003;
char s[N];
int linju[N];
int inq[N];
int main(){
    int h,w,i,k,j,num,u,ans=0;
    queue<int> q1,q2;
    scanf("%d %d",&h,&w);
    for(i=0;i<h;i++){
        scanf("%s",s+i*w);
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            k = j+i*w;
            num = 0;
            if(s[k]=='.'){inq[k]=1;}
            else{ans++;}
            if(i>0 && s[k-w]=='#')num++;
            if(i<h-1 && s[k+w]=='#')num++;
            if(j>0 && s[k-1]=='#')num++;
            if(j<w-1 && s[k+1]=='#')num++;
            linju[k]=num;
            if(num==1 && inq[k]){
                q1.push(k);
            }
            if(num>=1)inq[k]=0;
        }
    }
    while(q1.size()){
        while(q1.size()){
            u = q1.front();
            q1.pop();
            ans++;
            i = u/w;j = u%w;
            if(i>0){linju[u-w]++;if(inq[u-w])q2.push(u-w);}
            if(i<h-1){linju[u+w]++;if(inq[u+w])q2.push(u+w);}
            if(j>0){linju[u-1]++;if(inq[u-1])q2.push(u-1);}
            if(j<w-1){linju[u+1]++;if(inq[u+1])q2.push(u+1);}
        }
        while(q2.size()){
            u = q2.front();
            q2.pop();
            if(linju[u]==1){q1.push(u);}
            inq[u]=0;
        }
    }
    printf("%d",ans);
    return 0;
}