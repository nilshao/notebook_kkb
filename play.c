#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};
struct rectangle {
    struct point p1;
    struct point p2;
};

int main() {
    int x1,y1;
    int x2,y2,x3,y3;
    scanf("%d%d",&x1,&y1);
    scanf("%d%d%d%d",&x2,&y2,&x3,&y3);
    struct point p = {x1,y1};
    struct rectangle rec = {{x2,y2},{x3,y3}};
    if((y2-y1)*(y1-y3)>=0 && (x2-x1)*(x1-x3)>=0){
        printf("YES\n");return 0;
    }
    printf("NO\n");
    return 0;
}