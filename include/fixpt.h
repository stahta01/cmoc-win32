
#ifndef _FIXPT_H
#define _FIXPT_H

char fixsin(char x);
char fixcos(char x);

#define i2f(X) ((X)<<8)
#define f2i(X) ((X)>>8)

#define fixmul(X,Y) f2i((int)(X)*(int)(Y))

// OLD!!!!
#define _i2f(x) ((x)<<8)
#define _f2i(x) ((int)((char*)&(x))[0])

#endif

