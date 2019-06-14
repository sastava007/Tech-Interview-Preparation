#include <stdio.h>
int main()
{
    void demo();
    void (*fun)();
    fun = demo;
    (*fun)();
    fun();
    return 0;
}
 
void demo()
{
    printf("GeeksQuiz ");
}
