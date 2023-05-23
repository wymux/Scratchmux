def mysum(*args):
    sim = 0
    for arg in args:
        sim += int(arg)
    print(sim)
    return sim

mysum(1, 2)
mysum(1, 2, 3)
