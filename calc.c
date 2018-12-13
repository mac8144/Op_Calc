#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<math.h>

typedef struct postfix {
	double n;    //Operator, number
	short set;  //Operator = 0, number = 1
}Postfix;

void calc(int input1, char math, int input2);
void Icalc(int input);
void Dcalc(int input);

int Checks(char *s, Postfix *nums) {

	if (s[1000] != 0)
		return -1; //Input array exceeded


	int i, j;
	int t = 0, tt = 0; //If t is 0, if tt is 0, if tt is 1, then negative
	double n = 0; //Save number
	double d = 1; //Value to represent the point below the decimal point
	int nsp = 0;
	int notminus = 0; //Determine whether a minus is required
	int Parentheses = 0; //Parentheses check

	for (i = 0; s[i] != 0; i++) {              //Remove spaces
		if (s[i] == ' ') {
			for (j = i; s[j] != 0; j++)
				s[j] = s[j + 1];
			s[j] = 0;
			i--;
		}
	}

	for (i = 0; s[i] != 0; i++) {
		if ('0' <= s[i] && s[i] <= '9') {

			if (t == 0) {           //Variables that determine whether t is less than or equal to the decimal point
				n *= 10;			//Calculate two digits
				n += s[i] - 48;    //Because it is ASCII code
			}
			else {
				d *= 0.1;          //Calculate under decimal
				n += d * (s[i] - 48);
			}
		}
		else if (s[i] == '.') {   //Change the value of the variable to a decimal number
			t = 1;
		}
		else if (s[i] == '-' && (i == 0 || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '^' || s[i - 1] == '%')) {
			//'s[i - 1] == ')' Except for minus subtraction
			//The array 's' is a string containing the expression

			if (s[i + 1] == '(' && tt == 1) {
				s[i] = '+';
				tt = 0;
			}
			else if (s[i + 1] == '(' || tt == 1)  //If '(' is omitted, -1 is omitted. If tt == 1, - is used as a toggle because it is redundant.
				tt = 0;
			else
				tt = 1;
			//tt is a toggle key that separates negative or positive numbers

		}
		else if ((s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') && ((i == 0 || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '^' || s[i - 1] == '%') || !(('0' <= s[i + 1] && s[i + 1] <= '9') || s[i + 1] == '-' || s[i + 1] == '+'))) {
			return -4;
		}
		else if (s[i] == '!' && (i == 0 || !(('0' <= s[i - 1] && s[i - 1] <= '9') || s[i - 1] == ')' || s[i - 1] == '!' || s[i - 1] == 1) || ('0' <= s[i + 1] && s[i + 1] <= '9'))) {
			return -4;
		}
		else if (s[i] == '!' && i != 0 && s[i - 1] == 1) {
			s[i] = 1;
			nums[nsp].n = s[i];
			nums[nsp].set = 0;
			nums[nsp - 1].n = '!';

			nsp++;
		}
		else if (s[i] == '+' && (i == 0 || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '^' || s[i - 1] == '%')) {

		}

		else if (s[i] == '^' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '+' || s[i] == '-' || s[i] == ')' || s[i] == '(' || s[i] == '!') {
			if (i != 0) {
				if (s[i - 1] != '(' && s[i - 1] != ')' && s[i - 1] != '+' && s[i - 1] != '-' && s[i - 1] != '*' && s[i - 1] != '/' && s[i - 1] != '^' && s[i - 1] != '%' && s[i - 1] != '!') {

					if (tt != 0 && s[i] == '^') {
						s[i] = 6;
						tt = 0;
					}
					else if (tt != 0 && s[i] == '!') {
						s[i] = 1;
						tt = 0;
					}

					if (tt == 1)
						n *= -1;

					nums[nsp].n = n;
					nums[nsp].set = 1;
					nsp += 1;
					n = 0;
					d = 1;
					t = 0;
					tt = 0;

				}
			}



			if (s[i] == '(') {
				if (i != 0) {
					if ('0' <= s[i - 1] && s[i - 1] <= '9') {
						nums[nsp].n = '*';
						nums[nsp].set = 0;
						nsp++;
					}
					if (s[i - 1] == '-' && (i == 1 || s[i - 2] == '(' || s[i - 2] == '+' || s[i - 2] == '-' || s[i - 2] == '*' || s[i - 2] == '/' || s[i - 2] == '^' || s[i - 2] == 6 || s[i - 2] == '%')) {
						nums[nsp].n = -1;
						nums[nsp].set = 1;
						nsp++;
						nums[nsp].n = '*';
						nums[nsp].set = 0;
						nsp++;
					}
				}
				Parentheses++;
			}



			nums[nsp].n = s[i];
			nums[nsp].set = 0;
			nsp++;

			if (s[i] == ')') {
				if ('0' <= s[i + 1] && s[i + 1] <= '9') {
					nums[nsp].n = '*';
					nums[nsp].set = 0;
					nsp++;
				}
				Parentheses--;
				if (i != 0 && s[i - 1] == '(')
					return -2;

				if (i != 0 && (s[i - 1] == '+' || s[i - 1] == '-'))
					return -4;
			}

			if (Parentheses < 0)
				return -2; //Strange parentheses

		}
		else
			return -3; // Strange character
	}
	if (Parentheses != 0)
		return -2; //Strange parentheses

	if (i != 0) {
		if (s[i - 1] != '(' && s[i - 1] != ')' && s[i - 1] != '+' && s[i - 1] != '-' && s[i - 1] != '*' && s[i - 1] != '/' && s[i - 1] != '^' && s[i - 1] != '%' && s[i - 1] != '!' && s[i - 1] != 1) {


			if (tt == 1)
				n *= -1;

			nums[nsp].n = n;
			nums[nsp].set = 1;
			nsp++;

		}

		if (s[i - 1] == '+' || s[i - 1] == '-')
			return -4;

	}


	return nsp;
}

int ChangePostfix(Postfix *nums, Postfix *num, int cnt) {

	char stack[100] = { 0, };
	int i = 0, j = 0, Psp = 0, Ssp = 0;

	for (i = 0; i < cnt; i++) {

		if (nums[i].set == 1) {
			num[Psp].n = nums[i].n;
			num[Psp].set = 1;
			Psp++;
		}
		else {
			if (nums[i].n == ')') {

				for (j = Ssp - 1; stack[j] != '('; j--) {
					num[Psp].n = stack[j];
					num[Psp].set = 0;
					Psp++;
					stack[j] = 0;
				}
				Ssp = j;
				stack[j] = 0;
				if (Ssp >= 1) {
					if (stack[Ssp - 1] == '-' && (stack[Ssp - 2] == '(' || stack[Ssp - 2] == '+' || stack[Ssp - 2] == '-' || stack[Ssp - 2] == '*' || stack[Ssp - 2] == '/' || stack[Ssp - 2] == '^' || stack[Ssp - 2] == 6 || stack[Ssp - 2] == '%')) {
						num[Psp].n = -1;
						num[Psp].set = 1;
						Psp++;
						num[Psp].n = '*';
						num[Psp].set = 0;
						Psp++;
						stack[Ssp - 1] = 0;
						Ssp--;
					}
				}

			}
			else if (nums[i].n == '(') {

				if (nums[i - 1].n == ')' || ('0' <= nums[i - 1].n && nums[i - 1].n <= '9')) {
					if (Ssp != 0) {
						for (j = Ssp - 1; j >= 0 && stack[j] != '(' && stack[j] != '+' && stack[j] != '-'; j--) {
							num[Psp].n = stack[j];
							num[Psp].set = 0;
							Psp++;
							stack[j] = 0;
						}
						j++;
						Ssp = j;

					}
					stack[Ssp++] = '*';
				}

				stack[Ssp++] = (char)nums[i].n;

			}
			else if (nums[i].n == '!' || nums[i].n == 1) {
				if (Ssp != 0) {
					for (j = Ssp - 1; j >= 0 && stack[j] != '(' && stack[j] != '+' && stack[j] != '-' && stack[j] != '*' && stack[j] != '/' && stack[j] != '^' && stack[j] != 6 && stack[j] != '%'; j--) {
						num[Psp].n = stack[j];
						num[Psp].set = 0;
						Psp++;
						stack[j] = 0;
					}
					j++;
					Ssp = j;
				}
				stack[Ssp++] = (char)nums[i].n;
			}
			else if (nums[i].n == '^' || nums[i].n == 6) {

				if (Ssp != 0) {
					for (j = Ssp - 1; j >= 0 && stack[j] != '(' && stack[j] != '+' && stack[j] != '-' && stack[j] != '*' && stack[j] != '/' && stack[j] != '^' && stack[j] != 6 && stack[j] != '%'; j--) {
						num[Psp].n = stack[j];
						num[Psp].set = 0;
						Psp++;
						stack[j] = 0;
					}
					j++;
					Ssp = j;
				}
				stack[Ssp++] = (char)nums[i].n;

			}
			else if (nums[i].n == '*' || nums[i].n == '/' || nums[i].n == '%') {


				if (Ssp != 0) {
					for (j = Ssp - 1; j >= 0 && stack[j] != '(' && stack[j] != '+' && stack[j] != '-'; j--) {
						num[Psp].n = stack[j];
						num[Psp].set = 0;
						Psp++;
						stack[j] = 0;
					}
					j++;
					Ssp = j;
				}
				stack[Ssp++] = (char)nums[i].n;
				//stack[Ssp++] = 'n';
			}
			else if (nums[i].n == '+' || nums[i].n == '-') {

				if (Ssp != 0) {
					for (j = Ssp - 1; j >= 0 && stack[j] != '('; j--) {
						num[Psp].n = stack[j];
						num[Psp].set = 0;
						Psp++;
						stack[j] = 0;
					}
					j++;
					Ssp = j;
				}


				stack[Ssp++] = (char)nums[i].n;

			}
		}
	}


	for (j = Ssp - 1; j >= 0; j--) {
		num[Psp].n = stack[j];
		num[Psp].set = 0;
		Psp++;
		stack[j] = 0;
	}

	return Psp;
}

double Calculation(Postfix *num, int cnt) {

	double stack[100] = { 0, };
	int i, sp = 0;
	double j;
	double n1 = 0, n2 = 0;
	double fact = 1;
	for (i = 0; i < cnt; i++) {
		if (num[i].set == 1)
			stack[sp++] = num[i].n;
		else if (num[i].set == 0 && (num[i].n == 1 || num[i].n == '!')) {
			fact = 1;
			sp--;
			n1 = stack[sp];
			stack[sp] = 0;

			if (n1 < 1)
				n1 = 1;

			for (j = n1; j > 1; j--) {
				if (fact == INFINITY)
					break;

				fact *= j;
			}

			if (num[i].n == '!') {
				stack[sp] = fact;
				printf("%.2lf ! = %.2lf\n ", n1, fact);
			}
			else if (num[i].n == 1) {
				stack[sp] = -1.0 * fact;
				printf("%.2lf -! = %.2lf\n", n1, -1.0 * fact);
			}
			sp++;
		}
		else if (num[i].set == 0) {
			sp--;
			n2 = stack[sp];
			stack[sp--] = 0;
			n1 = stack[sp];

			printf("\n%.2lf %c %.2lf = ", n1, (int)(num[i].n), n2);

			if (num[i].n == '*') {
				stack[sp] = n1 * n2;
				printf("%.2lf", n1*n2);
			}
			else if (num[i].n == '/') {
				stack[sp] = n1 / n2;
				printf("%.2lf", n1 / n2);
			}
			else if (num[i].n == '+') {
				stack[sp] = n1 + n2;
				printf("%.2lf", n1 + n2);
			}
			else if (num[i].n == '-') {
				stack[sp] = n1 - n2;
				printf("%.2lf", n1 - n2);
			}
			else if (num[i].n == '^') {
				stack[sp] = pow(n1, n2);
				printf("%.2lf", pow(n1, n2));
			}
			else if (num[i].n == 6) {
				printf("\r                                 ");
				printf("\r%.2lf -^ %.2lf = ", n1, n2);
				stack[sp] = pow(n1, n2) * -1;
				printf("%.2lf", pow(n1, n2) * -1.0);
			}
			else if (num[i].n == '%') {
				stack[sp] = (int)n1 % (int)n2;
				printf("%d", (int)n1 % (int)n2);
			}

			sp++;
		}
	}
	return stack[sp - 1];
}


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
            printf("\n------------------------------------------------\n||\t\%.2fx^%d %c %.2fx^%d %c %.2f^2 + c|\n------------------------------------------------\n", (c_3_1/(c_3_2+1)), (c_3_2+1), math1, (c_2_1/(c_2_2+1)), (c_2_2+1), math2, (c_1/2));
            break;
        }
        case 2:
        {
            float c_4_1, c_3_1, c_2_1, c_1 = 0;
            int c_4_2 ,c_3_2, c_2_2, c_0=0;
            char math1, math2, math3, math4;
            printf("\tYou have selected four-dimension form.\n\tPlease enter the four-dimension form.(ex.4x^4+3x^3+2x^2+3x+1)\n>>");
            scanf("%fx^%d %c%fx^%d%c%fx^%d%c%fx^%d%c%fx%c%d",&c_4_1, &c_4_2, &math1, &c_3_1, &c_3_2, &math2, &c_2_1, &c_2_2, &math3, &c_1, &math4, &c_0);
            printf("\n------------------------------------------------\n||\t\%.2fx^%d %c %.2fx^%d %c %.2fx^%d %c %.2f^2 + c\n------------------------------------------------\n",(c_4_1/(c_4_2+1)), (c_4_2+1), math1, (c_3_1/(c_3_2+1)), (c_3_2+1), math2, (c_2_1/(c_2_2+1)), (c_2_2+1), math3, (c_1/2));
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
            printf("\n------------------------------------------------\n||\t\%dx^%d %c %dx^%d %c %d\n------------------------------------------------\n", (c_3_1*c_3_2), (c_3_2-1), math1, (c_2_1*c_2_2), (c_2_2-1), math2, c_1);
            break;
        }
        case 2:
        {
            int c_4_1, c_4_2, c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
            char math1, math2, math3, math4;
            printf("\tYou have selected four-dimension form.\n\tPlease enter the four-dimension form.(ex.4x^4+3x^3+2x^2+3x+1)\n>>");
            scanf("%dx^%d%c%dx^%d%c%dx^%d%c%dx%c%d", &c_4_1, &c_4_2, &math1, &c_3_1, &c_3_2, &math2, &c_2_1, &c_2_2, &math3, &c_1, &math4, &c_0);
            printf("\n------------------------------------------------\n||\t\%dx^%d %c %dx^%d %c %dx %c %d\n------------------------------------------------\n", (c_4_1*c_4_2), (c_4_2-1), math1, (c_3_1*c_3_2), (c_3_2-1), math2, (c_2_1*c_2_2), math3, c_1);
            break;
        }
        case 3:
        {
            int c_5_1, c_5_2, c_4_1, c_4_2, c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
            char math1, math2, math3, math4, math5;
            printf("\tYou have selected five-dimension form.\n\tPlease enter the five-dimension form.(ex.5x^5+4x^4+3x^3+2x^2+3x+1)\n>>");
            scanf("%dx^%d%c%dx^%d%c%dx^%d%c%dx^%d%c%dx%c%d", &c_5_1, &c_5_2, &math1, &c_4_1, &c_4_2, &math2, &c_3_1, &c_3_2, &math3, &c_2_1, &c_2_2, &math4, &c_1, &math5, &c_0);
            printf("\n------------------------------------------------\n||\t\%dx^%d %c %dx^%d %c %dx^%dx %c %d\n------------------------------------------------\n", (c_5_1*c_5_2), (c_5_2-1), math1, (c_4_1*c_4_2), (c_4_2-1), math2, (c_3_1*c_3_2), (c_3_2-1), math3, (c_2_1*c_2_2), math4, c_1);
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
    printf("\n------------------------\n||\t\t%d %c %d = %.2f\n------------------------\n", input1, math, input2, Answer);
    exit(1);
}


int main()
{
    int input, input1, input2=0;
    char math;
    
    char s[1001] = { 0, };
	Postfix num[1000] = { 0, };
	Postfix nums[1000] = { 0, };
	int cnt = 0;
	int i;
   
    while(1)
    {
        if(fork() == 0)
        {
            printf("\n  CALCULATOR");
            printf("\n  ----------\n");
            printf("\n 0) Complex formula");
            printf("\n 1) Simple Calc\n");
            printf("\n 2) Differential Calc\n");
            printf("\n 3) Integral Calc\n");
            
            printf("\n You want exit, Ctrl+C\n");
            printf("\n  ----------\n");
            scanf("%d", &input);
            
            if(input == 0){
		scanf("%1000[^\n]s", s);
		cnt = Checks(s, nums);
		    
                for (i = 0; i < cnt; i++) {
		        if (nums[i].set == 1)
			        printf("%.2lf ", nums[i].n);
		        else
			        if (nums[i].n == 6)
			        	printf("-^");
			        else if (nums[i].n == 1)
				        printf("-!");
			        else
				    printf("%c ", (int)nums[i].n);
	            }
                
                if (cnt >= 0) {
	            	printf("\n Replace with postfix operation : ");
	            	cnt = ChangePostfix(nums, num, cnt);

	        	for (i = 0; i < cnt; i++) {
	    		    if (num[i].set == 1)
	    			    printf("%.2lf ", num[i].n);
	    		    else {
	    			    if (num[i].n == 6)
	    			    	printf("-^ ");
		    		    else if (num[i].n == 1)
		    			    printf("-! ");
		    		    else
		    			    printf("%c ", (int)(num[i].n));
			        }
		       }
                    
		        printf("\n\n Calculation process : \n");
		        printf("\n\n Result : %.2lf\n", Calculation(num, cnt));
	            }
                
                else if (cnt == 0)
		            printf("No Data.\n");
	            else if (cnt == -1)
	            	printf("Array Overflow!\n");
	            else if (cnt == -2)
		            printf("Parenthesis Error!\n");
	            else if (cnt == -3)
	            	printf("There are strange characters.\n");
	            else if (cnt == -4)
	            	printf("Operator Error!\n");

	            return 0;
            }
            
            else if(input == 1)
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
