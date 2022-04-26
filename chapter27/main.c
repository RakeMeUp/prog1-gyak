#include <stdio.h>
#include <string.h>
int main(){
    //  1.
    //  printf("Hello World\n");
    
    //  2.
    //  this suck ass not gonna lie
    char first[100000] = "Hello";
    char second[100000] = "World!";
    char space[100000] = " ";

    strcat(first, space);
    strcat(first, second);
    printf("%s\n", first);

    //  3.
    // this took 4 weeks to make, pls appriciate
    void func(char* p, int x){
        printf("p is \"%s\", x is %d\n", p,x);
    }
    
    func("hello", 3);
    func("YOOOO", 9732);
    func("hello im under the water, please help me, here too much raining hueuueue", 1);
    func("what in tarnation", 69);

    return 0;
}