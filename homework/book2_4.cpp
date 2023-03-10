#include <iostream>

using namespace std;

const int MAX_LENGTH = 100;
char input[MAX_LENGTH];
int lookahead;

void error();
void S();
void match(char s);

int main()
{
    scanf("%s", input);

    S();

    return 0;
}

void error(int i)
{
    printf("synax error at $d\n", i);
}

void S()
{
    switch (input[lookahead])
    {
    case '+':
        match('+');
        S();
        S();
        break;
    case '-':
        match('-');
        S();
        S();
        break;
    case 'a':
        match('a');
        break;
    default:
        error();
    }
}

void match(char s)
{
    if (s == input[lookahead])
        lookahead++;
    else
        error(lookahead);
}