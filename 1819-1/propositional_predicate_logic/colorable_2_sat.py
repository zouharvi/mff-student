#!/bin/python3

import itertools

colorable = 9

(a,b,Nv, Ne) = input().split(' ')
Nv = int(Nv)
Ne = int(Ne)

vertexes = []
for v in range(Nv):
	vertexes.append([])

for e in range(Ne):
	(a, first, second) = input().split(' ')
	first = int(first)-1
	second = int(second)-1
	vertexes[first].append(second)
	#vertexes[second].append(first)

# vertex color id
def vci(vertex, color):
	return vertex*colorable + color

conditions = []

for v in range(Nv):
	t = v+1
	al = [list(x) for x in list(itertools.combinations_with_replacement([0,1], colorable))]
	for a in al:
		if sum(a) == 1:
			continue
		cond = []
		for i in range(colorable):
			if a[i] == 1:
				cond.append(-vci(t,i))
			else:
				cond.append(vci(t,i))
		# print(cond)
		conditions.append(cond)
	for s in vertexes[v]:
		st = s + 1
		for c in range(colorable):
			conditions.append([-vci(t,c), -vci(st, c)]);

print('p cnf ' + str(Nv*colorable) + ' ' + str(len(conditions)))
for cond in conditions:
	cond.append(0)
	print(' '.join(str(x) for x in cond))
