#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define		MAXTOKEN 100
#define		BUFSIZE	100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
char buf[BUFSIZE];
int bufp = 0;
