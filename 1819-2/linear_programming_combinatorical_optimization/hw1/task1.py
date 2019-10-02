#!/bin/env python3
V, E = [int(x) for x in input()[:-1].split(' ')[1:]]

print('var m;')
print('minimize obj: m;')
print('param V := ' + str(V-1) + ';')

# constant restrictions on vertex height
print('var v{i in (0..V)} >= 0, <= V;')

# min maximal vertex height
print('q{i in (0..V)}:  m >= v[i];')

# neighbouring verticies must have appropriate heights
for e in range(E):
    a, b = [int(x) for x in input().split(' --> ')]
    print('p' + str(e) + ': v[' + str(a) + '] + 1 <= v[' + str(b) + '];')

print('solve;')
print('printf "#OUTPUT: %d\\n", m;')
print('for {i in (0..V)} { printf "v_%d: %d\\n", i, v[i]; }')
print('printf "#OUTPUT END\\n";')
print('end;')