//Variables, operators and expressions
#include <stdio.h>

int main(void)
{
    // 1
    printf("%d\n", 7 / 2);//3
    printf("%f\n", 7 / 2.0);//3.5
    printf("%d\n", 7 % 2);// 1

    // 2
    int i = 5;
    int j = i++;
    int k = ++i;
    printf("%d %d %d\n", i, j, k);//5 6 6
    /*all predictions are wrong, answer was 7 5 7 :
    x++ → use x, then add 1. ++x → add 1, then use x. Both change x.
    When the line is just i++; on its own, the two forms do the same thing.
    The difference only shows when the value is used, as in j = i++
    */

    // 3
    int x = 10;
    x += 5;
    x *= 2;
    printf("%d\n", x);// 30

    // 4
    int a = 0;
    int b = (a != 0) && (10 / a > 1);
    printf("%d\n", b);// 0 or false

    // 5
    int y = 7;
    printf("%s\n", y % 2 == 0 ? "even" : "odd");// odd

    return 0;
}