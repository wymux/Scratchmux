# Exercise 1-2

* Experiment to find out what happens when `printf`'s argument string contains `\c`,
where `c` is some character not listed above.

```
main.c: In function ‘main’:
main.c:8:20: warning: unknown escape sequence: '\c'
    8 |         printf("\c");
      |                    ^
```

```
$ ./main
hello, worldc
```
