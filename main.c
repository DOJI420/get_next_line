#include <stdio.h>

int num(int num)
{
    static int a = 0;
    a++;
    return (num + a);
}

int main(){
    static int i = 5;

    printf("%d\n", num(i));
    printf("%d\n", num(i));
    printf("%d\n", num(i));
    printf("%d\n", num(i));
    return 0;
}