#include <stdio.h>

int search(int *data, int length, int value) {
    int i=0;
    for(i=0; i<length; ++i){
        if(data[i]==value){
            printf("%d ",i+1);
            return i;
        }
        else if(data[i]>value){
            printf("%d ",i+1);
            return -1;
        }
    }
    printf("%d ",i);
    return -1;
}

int main() {
    /*
    int a[101];
    for(int i=0;i<=100;++i){
        a[i]=0;
    }
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",a[i]);
    }
//    int[n]=int[0]-1;
    

    */
    int a[100];
    for(int i=0;i<100;++i){
        a[i]=0;
    }
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
  
    
    
    int p;
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&p);
        int res = search(a, n, p);
        if( res == -1){
            printf("failed\n");
        }else{
            printf("%d\n", res);
        }
        
    }
    return 0;
}