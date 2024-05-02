#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
void top_print(void);
void top_swap(void);
void top_duplicate(void);
void stack_print(void);
void stack_clear(void);

int main() {
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				//top_duplicate();	
				//top_swap();
				stack_print();
				top_print();
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: division with 0");
				break;
			case '%':
				op2 = pop();
				if (op2)
					 push(fmod(pop(), op2));
				else
					printf("Error: division with 0");
				break;
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: unknown operation");
				break;
		}
	}
	return 0;
}

#define MAXVAL 100

int stack_pointer = 0;
double val[MAXVAL];

void stack_clear() {
	stack_pointer = 0;
}
void stack_print() {
	printf("\n");
	for (int i = 0; i < stack_pointer; i++) {
		printf("%g ", val[i]);
	}
	printf("\n");
}
void top_duplicate() {
	if (stack_pointer != 0) {
		val[stack_pointer++] = val[stack_pointer-1];
	}
	else printf("error: stack is empty\n");
}
void top_swap() {
	if (stack_pointer >= 2) {
		double tmp = val[stack_pointer - 2];
		val[stack_pointer-2] = val[stack_pointer-1];
		val[stack_pointer-1] = tmp;
	} else printf("\nerror: not enough elements in the stack for a swap\n");
}
void top_print() {
	printf("\nTop : %g\n", val[stack_pointer-1]);	
}

void push(double f) {
	if (stack_pointer<MAXVAL)
		val[stack_pointer++] = f;
	else
		printf("Error: stack full, can't push %g\n", f);
}

double pop(void) {
	if (stack_pointer > 0) {
		return val[--stack_pointer];
	}
	else printf("error: stack empty");
	return 0.0;
}


int getch(void);
void ungetch(int);

int getop(char s[]) {
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0;
	if (c  == '-') {
		s[i] = c;
		if (!isdigit(c = getch())) {
			return '-';
		}
		else
			s[++i] = c;
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
				;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFFSIZE 100
char buffer[BUFFSIZE];
int buffer_pointer = 0;

int getch(void) {
	return (buffer_pointer > 0) ? buffer[--buffer_pointer] : getchar();
}

void ungetch(int c) {
	if (buffer_pointer > BUFFSIZE)
		printf("ungetch: too many characters\n");
	else
		buffer[buffer_pointer++] = c; }
