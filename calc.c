#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void calc(int input1, char math, int input2);
void Icalc(int input);
void Dcalc(int input);

void Icalc(int input)
{
    switch(input)
    {
        case 1:
        {
            float c_3_1, c_2_1, c_1=0;
            int c_3_2, c_2_2, c_0=0;
            char math1, math2, math3;
            printf("\tYou have selected three-dimension form.\n\tPlease enter the three-dimension form.(ex.3x^3+2x^2+3x+1)\n>>");
            scanf("%fx^%d%c%fx^%d%c%fx%c%d", &c_3_1, &c_3_2, &math1, &c_2_1, &c_2_2, &math2, &c_1, &math3, &c_0);
            printf("\n------------------------\n||\t\%.2fx^%d%c%.2fx^%d%c%.2f^2+c\t\t||\n------------------------\n", (c_3_1/(c_3_2+1)), (c_3_2+1), math1, (c_2_1/(c_2_2+1)), (c_2_2+1), math2, (c_1/2));
            break;
        }
        case 2:
        {
            float c_4_1, c_3_1, c_2_1, c_1 = 0;
            int c_4_2 ,c_3_2, c_2_2, c_0=0;
            char math1, math2, math3, math4;
            printf("\tYou have selected four-dimension form.\n\tPlease enter the four-dimension form.(ex.4x^4+3x^3+2x^2+3x+1)\n>>");
            scanf("%fx^%d%c%fx^%d%c%fx^%d%c%fx^%d%c%fx%c%d",&c_4_1, &c_4_2, &math1, &c_3_1, &c_3_2, &math2, &c_2_1, &c_2_2, &math3, &c_1, &math4, &c_0);
            printf("\n------------------------\n||\t\%.2fx^%d%c%.2fx^%d%c%.2fx^%d%c%.2f^2+c\t\t||\n------------------------\n",(c_4_1/(c_4_2+1)), (c_4_2+1), math1, (c_3_1/(c_3_2+1)), (c_3_2+1), math2, (c_2_1/(c_2_2+1)), (c_2_2+1), math3, (c_1/2));
            break;
        }
        case 3:
        {
            int c_5_1, c_5_2, c_4_1, c_4_2, c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
            char math1, math2, math3, math4, math5;
            printf("\tYou have selected five-dimension form.\n\t식을 입력 해주세요.(ex.5x^5+4x^4+3x^3+2x^2+3x+1)\n>>");
            scanf("%dx^%d%c%dx^%d%c%dx^%d%c%dx^%d%c%dx%c%d", &c_5_1, &c_5_2, &math1, &c_4_1, &c_4_2, &math2, &c_3_1, &c_3_2, &math3, &c_2_1, &c_2_2, &math4, &c_1, &math5, &c_0);
            printf("\n------------------------\n||\t\%dx^%d%c%dx^%d%c%dx^%d%c%d\t\t||\n------------------------\n", (c_5_1*c_5_2), (c_5_2-1), math1, (c_4_1*c_4_2), (c_4_2-1), math2, (c_3_1*c_3_2), (c_3_2-1), math3, (c_2_1*c_2_2), math4, c_1);
            break;
        }
        exit(1);
    }
}
void Dcalc(int input)
{
    switch(input)
    {
        case 1:
        {
            int c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
            char math1, math2, math3;
            printf("\tYou have selected three-dimension form.\n\tPlease enter the three-dimension form.(ex.3x^3+2x^2+3x+1)\n>>");
            scanf("%dx^%d%c%dx^%d%c%dx%c%d", &c_3_1, &c_3_2, &math1, &c_2_1, &c_2_2, &math2, &c_1, &math3, &c_0);
            printf("\n------------------------\n||\t\%dx^%d%c%dx^%d%c%d\t\t||\n------------------------\n", (c_3_1*c_3_2), (c_3_2-1), math1, (c_2_1*c_2_2), (c_2_2-1), math2, c_1);
            break;
        }
        case 2:
        {
            int c_4_1, c_4_2, c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
            char math1, math2, math3, math4;
            printf("\tYou have selected four-dimension form.\n\tPlease enter the four-dimension form.(ex.4x^4+3x^3+2x^2+3x+1)\n>>");
            scanf("%dx^%d%c%dx^%d%c%dx^%d%c%dx%c%d", &c_4_1, &c_4_2, &math1, &c_3_1, &c_3_2, &math2, &c_2_1, &c_2_2, &math3, &c_1, &math4, &c_0);
            printf("\n------------------------\n||\t\%dx^%d%c%dx^%d%c%dx%c%d\t\t||\n------------------------\n", (c_4_1*c_4_2), (c_4_2-1), math1, (c_3_1*c_3_2), (c_3_2-1), math2, (c_2_1*c_2_2), math3, c_1);
            break;
        }
        case 3:
        {
            int c_5_1, c_5_2, c_4_1, c_4_2, c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
            char math1, math2, math3, math4, math5;
            printf("\tYou have selected five-dimension form.\n\tPlease enter the five-dimension form.(ex.5x^5+4x^4+3x^3+2x^2+3x+1)\n>>");
            scanf("%dx^%d%c%dx^%d%c%dx^%d%c%dx^%d%c%dx%c%d", &c_5_1, &c_5_2, &math1, &c_4_1, &c_4_2, &math2, &c_3_1, &c_3_2, &math3, &c_2_1, &c_2_2, &math4, &c_1, &math5, &c_0);
            printf("\n------------------------\n||\t\%dx^%d%c%dx^%d%c%dx^%dx%c%d\t\t||\n------------------------\n", (c_5_1*c_5_2), (c_5_2-1), math1, (c_4_1*c_4_2), (c_4_2-1), math2, (c_3_1*c_3_2), (c_3_2-1), math3, (c_2_1*c_2_2), math4, c_1);
            break;
        }
            exit(1);
    }
}
void calc(int input1, char math, int input2)
{
    float Answer;
    switch(math)
    {
        case '+':
            Answer = input1 + input2;
            break;
        case '-':
            Answer = input1 - input2;
            break;
        case '*':
            Answer = input1 * input2;
            break;
        case '/':
            Answer = input1 / input2;
            break;
    }
    printf("\n------------------------\n||\t\t%d %c %d = %f ||\n------------------------\n", input1, math, input2, Answer);
    exit(1);
}


int main()
{
    int input, input1, input2=0;
    char math;
    while(1)
    {
        if(fork() == 0)
        {
            printf("\n  CALCULATOR");
            printf("\n  ----------\n");
            printf("\n 1) Simple Calc\n");
            printf("\n 2) Differential Calc\n");
            printf("\n 3) Integral Calc\n");
            printf("\n You want exit, Ctrl+C\n");
            printf("\n  ----------\n");
            scanf("%d", &input);
            
            if(input == 1)
            {
                printf("You Choose Simple Calc.\nPlease enter numerical expression(ex. 3*4)\n>>");
                scanf("%d%c%d", &input1, &math, &input2);
                calc(input1, math, input2);
            }
            else if(input == 2)
            {
                printf("You Choose Differential Calc.\nThree-degree = 1, Four-degree = 2, five-degree = 3\n>>");
                scanf("%d", &input);
                Dcalc(input);
                exit(1);
            }
            else if(input == 3)
            {
                printf("You Choose Integral Calc.\nThree-degree = 1, Four-degree = 2, five-degree = 3\n>>");
                scanf("%d", &input);
                Icalc(input);
                exit(1);
            }
        }
        else{
            wait((int *) 0);
            printf("Kill the Child Process\n");
        }
    }
}
