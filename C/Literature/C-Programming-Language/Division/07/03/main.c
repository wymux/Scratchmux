#include <stdarg.h>
#include <stdio.h>

static void
minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	int oval;
	unsigned int uval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch(*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 'o':
			oval = va_arg(ap, int);
			printf("%o", oval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		case 'u':
			uval = va_arg(ap, unsigned int);
			printf("%u", uval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}

int
main()
{
	minprintf("%o\n", 0123);
	minprintf("%u\n", 567889);
	return 0;
}
