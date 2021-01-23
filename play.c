#include <stdio.h>
#include <math.h>

void unit(int i,int j){
    printf("%d*%d=%d",i,j,i*j);
    return ;
}

int main() {
    /*
    int n;
    scanf("%d",&n);
    double res=13;
    if(n<=3){
        res = 13;
    }else{
        res+=(n-3)*2.3;
    }
    printf("%.1lf\n",res+1);
*/

    char x;
    int num;
    while(~scanf("%c",&x)){
        if(x>='0'&&x<='9'){
            num = x-'0';
        }
        else{
            if(num%2==0){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
            
        }
    }
    
    
    return 0;
}