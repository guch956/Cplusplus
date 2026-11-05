#include<cstdio>
int main(){
    int N,line,a,H,Delta,i,j,*max_line,*shu,**shizi;
    scanf("%d %d %d",&N,&H,&Delta);
    shizi = new int*[N];
    for(i=0;i<N;i++){
        shizi[i] = new int[H+1];
        for(j=0;j<=H;j++){
            shizi[i][j]=0;
        }
    }
    for(i=0;i<N;i++){
        scanf("%d",&line);
        for(j=0;j<line;j++){
            scanf("%d",&a);
            shizi[i][a]++;
        }
    }
    shu = new int[N];
    max_line = new int[H+1];
    line = -1;
    for(i=0;i<N;i++){
        shu[i] = shizi[i][H];
        if (shu[i]>line){
            line = shu[i];
        }
    } 
    max_line[H]=line;
    for(i=H-1;i>H-Delta;i--){
        line = -1;
        for(j=0;j<N;j++){
            shu[j] = shu[j]+shizi[j][i];
            if (shu[j]>line){
                line = shu[j];
            }
        }
        max_line[i] = line;
    }
    for(i=H-Delta;i>=0;i--){
        line = -1;
        for(j=0;j<N;j++){
            a = max_line[i+Delta]>shu[j]?max_line[i+Delta]:shu[j];
            shu[j] = a+shizi[j][i];
            if (shu[j]>line){
                line = shu[j];
            }
        }
        max_line[i] = line;
    }
    printf("%d",max_line[0]);
    return 0;
}