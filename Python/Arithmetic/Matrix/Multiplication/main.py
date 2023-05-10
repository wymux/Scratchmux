from array import *
import timeit

arr = [[3, 4], [1, 2]]
arr1 = [[5, 4], [1, 3]]

def arr2():
    _arr2 = [
    [((arr[0][0] * arr1[0][0]) + (arr[0][1] * arr1[1][0]))],
    [((arr[0][0] * arr1[0][1]) + (arr[0][1] * arr1[1][1]))],
    [((arr[0][1] * arr1[0][0]) + (arr[1][1] * arr1[1][0]))],
    [((arr[0][1] * arr1[0][1]) + (arr[1][1] * arr1[1][1]))],
    ]

duration = timeit.timeit(arr2, number=10000000)

print(f"Time: {duration}\n")
