
#include<stdio.h>


int main(){
     int n,m;
     scanf("%d %d",&n,&m);
     int a[n+5][m+5];
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
     }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m/2;j++){
            int tmp = a[i][j];
            a[i][j]=a[i][m-j+1];
            a[i][m-j+1]=tmp;
        }
     }
     for(int i=1;i<=n;i++){
        for(int j=i;j<=m;j++){
            int tmp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=tmp;
        }
     }


     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
     }


}
