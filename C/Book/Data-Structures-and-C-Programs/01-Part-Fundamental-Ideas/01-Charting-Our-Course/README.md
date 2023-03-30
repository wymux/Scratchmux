1. Give a persuasive argument that Program 1.1 is correct.

 * The program calculates the balance of negative sums correctly.

 * The program perses input correctly.

 * The program submits the remaining balances correctly.

2. Modify Program 1.1 to check that the account number is valid before it posts a change to the account.

 * [Modified program](Exercise/2/1_1_2.c)

3. How many accounts does Program 1.1 examine to find the one that corresponds to the input? In other words, what value of "numseen" should we report for Program 1.1 given the value of `numfound`?

 * [Modified program](Exercise/3/1_1_3.c)

 * One account

4. Modify Program 1.1 so it does not produce output for accouts with a balance of zero. Duscuss the good and bad points of the resulting program. Can you modify Program 1.1 to output all *active* accounts-those whose balance was non-zero at some time during program execution-even if an active account has zero balance at the end of the program?

 * [Modified program](Exercise/4/1_1_4.c)

 * Bad: User is uninformed account number with zero balance; force to manually search for missing number

 * Good: Declutter output

 * [Modified program](Exercise/4/1_1_4_2.c)

 