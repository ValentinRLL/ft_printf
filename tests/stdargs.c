#include <stdarg.h>
#include <stdio.h>

void	foo(int type, int count, ...)
{
	va_list ap;
	int d;
	char c, *s;

	va_start(ap, count);
	while (count--)
		switch (type) {
			case 0:
				s = va_arg(ap, char *);
				printf("chaîne %s\n", s);
				break;
			case 1:
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 2:
				c = (char)va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	va_end(ap);
}

void	bar(int count, ...)
{
	va_list ap;
	long long d;
	char c, *s;

	va_start(ap, count);
	while (count--)
	{
		d = va_arg(ap, long long);
		printf("long long %lld\n", d);
		printf("unsigned char %hhu\n", (unsigned char)d);
	}
	va_end(ap);
}
int	main(void)
{
	foo(0, 2, "hello world", "ok");
	foo(1, 4, 18, 22, -14, 5);
	foo(2, 1, 'f');
	bar(4, 10, 15, 20, 1000);
	return (0);
}
