# Exercise 8-07

- `malloc` accepts a size request without checking its plausibility;
`free` believes that the block it is asked tofree contains a valid size field.
Improve these routines so they take more pains with error checking.
