#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

void reverse(char *start, char *end)
{
	while (start < end){
		char t = *start;
		*start = *end;
		*end = t;
		++start;
		--end;
	}
}

#define IN  1
#define OUT 0 

int is_space(char c)
{
	return c == ' ' || c == '\t' || c == '\n';
}

int main(void)
{
	char buf[] = "student    a     am      i";

	printf("before = [%s]\n", buf);
	reverse(buf, buf + strlen(buf) - 1);
	printf("after  = [%s]\n", buf);

	int status = OUT;

	char *ks = NULL;
	char *js = NULL;
	// scan string
	int i;
	for (i = 0; buf[i] != '\0'; i++) {
		if (!is_space(buf[i]) && status == OUT) {
			status = IN;
			ks = buf + i; // the word begins
		}
		else if (is_space(buf[i]) && status == IN) {
			status = OUT;
			js = buf + i - 1;
			reverse(ks, js);
		}
		printf("%c %d\n", buf[i], status);
	}
	reverse(ks, buf + i - 1);
	printf("after 2  = [%s]\n", buf);
	system("pause");
	return;
}
