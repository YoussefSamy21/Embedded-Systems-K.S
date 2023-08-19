#include <stdio.h>
// C program to make a simple calculator (Add , Multiply , Subtract or Divide)
int main()
{
	char op;
	float num1,num2;
	printf("Enter operator either + or - or * or / : ");
	scanf("%c",&op);
	switch(op)
	{
		case '-':
			printf("Enter two operands: ");
			scanf("%f %f",&num1,&num2);
			printf("%f - %f = %f",num1,num2,num1-num2);
			break;
		
		case '+':
			printf("Enter two operands: ");
			scanf("%f %f",&num1,&num2);
			printf("%f + %f = %f",num1,num2,num1+num2);
			break;
		
		case '*':
			printf("Enter two operands: ");
			scanf("%f %f",&num1,&num2);
			printf("%f * %f = %f",num1,num2,num1*num2);
			break;
		
		case '/':
			printf("Enter two operands: ");
			scanf("%f %f",&num1,&num2);
			printf("%f / %f = %f",num1,num2,num1/num2);
			break;
		
		default:
			printf("ERROR!");
	}
	
	return 0;
}