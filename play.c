#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <inttypes.h>
/*
int isSquare(long long num){
    int tmp = (int)pow(num,0.5);
    long long tmp2 = (long long)tmp * tmp;
    return tmp2==num;
}

int main() {
    int a,b,c;
    scanf("%d",&c);
    long long target = (long long)c*c;
    printf("%d\n",c);
    printf("%lld\n",target);
    int count =0;
    for(int i=1;(long long)i*i<target-i*i;++i){
        if(isSquare(target-i*i)){
            count++;

        }
    }
    printf("%d\n",count);
    return 0;*/

#define P(func){\
    printf("%s = %d\n",#func,func);\
}
int max_int(int n, ...){
    int ans = INT32_MIN;
    va_list arg;
    va_start(arg,n);
    while(n--){
        

        int tmp=va_arg(arg,int);
        printf("%d ",tmp);
        if(tmp>ans)ans=tmp;
    }
    va_end(arg);
    return ans;
}
int main(){
    int a,b=0;
    scanf("%d",&a);
    int c = a;
    while(c){
        b=b*10+c%10;
        c/=10;
    }
    (a==b)?printf("YES\n"):printf("NO\n");
    return 0;
}   