
# include <stdio.h>
# include <cs50.h>


int main(void)
{
    //1. Ask name
    string name = get_string("What is your name?\n");
    //2. Input name into hello (name)
    printf("Hello, %s\n", name);
}
