#include<stdio.h>
char exp[20],*e;
int stack[10],top = -1;
int isOperator(char c){
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){
		return 1;
	}else{
		return 0;
	}
}
void push(int i){
	if(top < 10){
		top++;
		stack[top] = i;
	}
}
int pop(){
	if(top != -1){
		return stack[top--];
	}
}
int main(){
	int a,b,c,t;
	printf("Enter a postfix expression\n");
	scanf("%s",&exp);
	e = exp;
	while(*e != '\0'){
		if(isOperator(*e) == 0){
			t = *e - '0';
			push(t);
		}else{
			a = pop();
			b = pop();
			if(*e == '+'){
				c = b + a;
			}
			if(*e == '-'){
				c = b - a;
			}
			if(*e == '*'){
				c = b * a;
			}
			if(*e == '/'){
				c = b / a;
			}
			push(c);
		}
		e++;
	}
	printf("Evaluation is : %d\n",stack[top]);
	return 0;
}
