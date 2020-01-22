#!/usr/bin/env python3
import random, time

ITERS = 10**6 
SIZE  = 3
SUCCESS = True

TIME_0 = time.time()
struct = set(range(SIZE))
#struct = list(range(SIZE))

for i in range(ITERS):
    x = random.randrange(SIZE) + (0 if SUCCESS else SIZE)
    _ = x in struct

TIME_1 = time.time()

print(TIME_1 - TIME_0)
