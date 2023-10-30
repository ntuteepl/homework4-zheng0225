#include <stdio.h>

int i,k,a,b[50],dec[50];
int main(){
    while (a<1 || a>50)
        scanf("%d",&a);

    for (i=0;i<a;i++){
        fflush(stdin);
        scanf("%d",&b[i]);
    }
    for (i=0;i<a;i++){
        for (k=2;k<b[i];k++){
            if (b[i]%k==0)
                dec[i]=1;
        }
        if (dec[i]==0)
            printf("YES ");
        else
            printf("NO ");
    }

    return 0;
}

