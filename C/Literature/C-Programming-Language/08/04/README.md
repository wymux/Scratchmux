# Exercise 8-04

- The standard library function
```
int fseek(FILE *fp, long offset, int origin)
```
is identical to `lseek` except that `fp` is a file pointer instead of a file descriptor
and the return value is and `int` status, not a position.
Write `fseek`. Make sure that your `fseek` coordinates properly with the buffering done for the other functions of the library.
