#include<stdio.h>

int calc(char math);

int main()
{
	int input, input1, input2=0;
	char math;
	while(1)
	{
		printf("\n  CALCULATOR");
		printf("\n  ----------\n");
		printf("\n 1) 수식계산기\n");
		printf("\n 2) 미분계산기\n");
		printf("\n 3) 적분계산기\n");
		printf("\n 4) Exit\n");
		printf("\n  ----------\n");
		scanf("%d", &input);
		
		if(input == 1)
		{
			printf("수식 계산기를 선택하셨습니다.\n식을 입력하세요.(ex. 3*4)\n>>");
			scanf("%d%c%d", &input1, &math, &input2);
			calc(input1, math, input2);
		}
		else if(input == 2)
		{
			printf("미분 계산기를 선택하셨습니다.\n3차식-1, 4차식-2, 5차식-3\n>>");
			scanf("%d", &input);
			Dcalc(input);
		}
		else if(input == 3)
		{
			printf("적분 계산기를 선택하셨습니다.\n3차식-1, 4차식-2, 5차식-3\n>>");
			scanf("%d", &input);
			Icalc(input);
		}
	return 0;
}
void Icalc(int input)
{
	switch(input)
	{
		case 1:
			double c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0=0;
			char math1, math2, math3;
			printf("\t3차식을 선택하셨습니다.\n\t식을 입력 해주세요.(ex.3x^3+2x^2+3x+1)\n>>");
			scanf("%fx^%f%c%fx^%f%c%fx%c%d", &c_3_1, &c_3_2, &math1, &c_2_1, &c_2_2, &math2, &c_1, &math3, &c_0);
			printf("\n------------------------\n||\t\%fx^%f%c%fx^%f%c%f^2+c\t\t||\n------------------------\n", (c_3_1/(c_3_2+1)), (c_3_2+1), math1, (c_2_1/(c_2_2+1)), (c_2_2+1), math2, (c_1/2);
			break;
		case 2:
			double c_4_1, c_4_2, c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
			char math1, math2, math3, math4;
			printf("\t4차식을 선택하셨습니다.\n\t식을 입력 해주세요.(ex.4x^4+3x^3+2x^2+3x+1)\n>>");
			scanf("%fx^%f%c%fx^%f%c%fx^%f%c%fx^%f%c%fx%c%d",&c_4_1, &c_4_2, &math1 &c_3_1, &c_3_2, &math2, &c_2_1, &c_2_2, &math3, &c_1, &math4, &c_0);
			printf("\n------------------------\n||\t\%fx^%f%c%fx^%f%c%fx^%f%c%f^2+c\t\t||\n------------------------\n",(c_4_1/(c_4_2+1)), (c_4_2+1), math1, (c_3_1/(c_3_2+1)), (c_3_2+1), math2, (c_2_1/(c_2_2+1)), (c_2_2+1), math3, (c_1/2);
			break;
		case 3:
			int c_5_1, c_5_2, c_4_1, c_4_2, c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
			char math1, math2, math3, math4, math5;
			printf("\t5차식을 선택하셨습니다.\n\t식을 입력 해주세요.(ex.5x^5+4x^4+3x^3+2x^2+3x+1)\n>>");
			scanf("%dx^%d%c%dx^%d%c%dx^%d%c%dx^%d%c%dx%c%d", &c_5_1, %c_5_2, &math1, &c_4_1, &c_4_2, &math2, &c_3_1, &c_3_2, &math3, &c_2_1, &c_2_2, &math4, &c_1, &math5, &c_0);
			printf("\n------------------------\n||\t\%dx^%d%c%dx^%d%c%dx^%d%c%d\t\t||\n------------------------\n", (c_5_1*c_5_2), (c_5_2-1), math1, (c_4_1*c_4_2), (c_4_2-1), math2, (c_3_1*c_3_2), (c_3_2-1), math3, (c_2_1*c_2_2), math4, c_1);
			break;
	}
}
void Dcalc(int input)
{
	switch(input)
	{
		case 1:
			int c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
			char math1, math2, math3;
			printf("\t3차식을 선택하셨습니다.\n\t식을 입력 해주세요.(ex.3x^3+2x^2+3x+1)\n>>");
			scanf("%dx^%d%c%dx^%d%c%dx%c%d", &c_3_1, &c_3_2, &math1, &c_2_1, &c_2_2, &math2, &c_1, &math3, &c_0);
			printf("\n------------------------\n||\t\%dx^%d%c%dx^%d%c%d\t\t||\n------------------------\n", (c_3_1*c_3_2), (c_3_2-1), math1, (c_2_1*c_2_2), math2, c_1);
		case 2:
			int c_4_1, c_4_2, c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
			char math1, math2, math3, math4;
			printf("\t4차식을 선택하셨습니다.\n\t식을 입력 해주세요.(ex.4x^4+3x^3+2x^2+3x+1)\n>>");
			scanf("%dx^%d%c%dx^%d%c%dx^%d%c%dx%c%d", &c_4_1, &c_4_2, &math1, &c_3_1, &c_3_2, &math2, &c_2_1, &c_2_2, &math3, &c_1, &math4, &c_0);
			printf("\n------------------------\n||\t\%dx^%d%c%dx^%d%c%d\t\t||\n------------------------\n", (c_4_1*c_4_2), (c_4_2-1), math1, (c_3_1*c_3_2), (c_3_2-1), math2, (c_2_1*c_2_2), math3, c_1);
			break;
		case 3:
			int c_5_1, c_5_2, c_4_1, c_4_2, c_3_1, c_3_2, c_2_1, c_2_2, c_1, c_0 = 0;
			char math1, math2, math3, math4, math5;
			printf("\t5차식을 선택하셨습니다.\n\t식을 입력 해주세요.(ex.5x^5+4x^4+3x^3+2x^2+3x+1)\n>>");
			scanf("%dx^%d%c%dx^%d%c%dx^%d%c%dx^%d%c%dx%c%d", &c_5_1, %c_5_2, &math1, &c_4_1, &c_4_2, &math2, &c_3_1, &c_3_2, &math3, &c_2_1, &c_2_2, &math4, &c_1, &math5, &c_0);
			printf("\n------------------------\n||\t\%dx^%d%c%dx^%d%c%dx^%d%c%d\t\t||\n------------------------\n", (c_5_1*c_5_2), (c_5_2-1), math1, (c_4_1*c_4_2), (c_4_2-1), math2, (c_3_1*c_3_2), (c_3_2-1), math3, (c_2_1*c_2_2), math4, c_1);
			break;
	}
}
int calc(int input1, char math, int input2)
{
	double Answer;
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
					Answer = input1 / inptu2;
					break;
			}
			printf("\n------------------------\n||\t\t%d %c %d = %f\t\t||\n------------------------\n", input1, math, input2, Answer);
}
