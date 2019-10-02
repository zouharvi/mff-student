#!/bin/env python3

V, E = [int(x) for x in input()[:-1].split(' ')[2:]]
weights = []
edges = []

# load the edges
for v in range(E):
    a, b, w = [int(x) for x in input().replace(' --> ', ' ').replace('(', ' ').replace(')', '').split()]
    edges.append((a, b))
    weights.append(w)

# create glpsol Edges set and make it non-negative integer
print('set Edges := {' + ', '.join(['"' + str(e[0]) + ' --> ' + str(e[1]) + '" ' for e in edges]) + '};')
print('var x{i in Edges}, >= 0, integer;') 

# generate conditions
cond_num = 0
def cond_id():
    global cond_num
    cond_num += 1
    return 'p' + str(cond_num-1) + ': '

# construct edge name from id
def edge_id(i):
    return 'x["' + str(edges[i][0]) + ' --> ' + str(edges[i][1]) + '"]'

# four inner for-cycles will find all 3- and 4-cycles
# if found, create a condition so that at least one edge will have to be removed  
for a1 in range(0, E):
    for a2 in range(0, E):
        if edges[a1][1] == edges[a2][0]:
            for a3 in range(0, E):
                if edges[a2][1] == edges[a3][0]:
                    if edges[a3][1] == edges[a1][0]:
                        # found
                        print(cond_id() + '+'.join([edge_id(i) for i in [a1,a2,a3]]) + ' >= 1;')
                    else:    
                        for a4 in range(a3, E):
                            if edges[a3][1] == edges[a4][0] and edges[a4][1] == edges[a1][0]:
                                # found
                                print(cond_id() + '+'.join([edge_id(i) for i in [a1,a2,a3,a4]]) + ' >= 1;')

print('var m;')
# minimize edge removal cost
print('pM: m >= ' + '+'.join([edge_id(i) + '*' + str(weights[i]) for i in range(E)]) + ';') 
print('minimize obj: m;')
print('solve;')
print('printf "#OUTPUT: %d\\n", m;')
# print if edge removed
print('for {e in Edges: x[e] == 1} { printf "%s\\n", e; }')
print('printf "#OUTPUT END\\n";')
print('end;')