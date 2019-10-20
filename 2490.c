#include<stdio.h>
int main()
{
    for(int i=0, a,b,c,d;i<3;i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        char cc;
        switch(a+b+c+d){
            case 1:
            cc='C';
            break;
            case 2:
            cc='B';
            break;
            case 3:
            cc='A';
            break;
            case 4:
            cc='E';
            break;
            case 0:
            cc='D';
            break;
        }
        printf("%c\n", cc);
    }
    return 0;
}