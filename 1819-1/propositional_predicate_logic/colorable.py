#!/bin/python3

import sys
import itertools
#import glucose

vertices = []
edges = []

def read_graph(filename):
	with open(filename) as f:
		vert_num = -1
		edg_num = -1
		for line in f.readlines():
			if line.startswith('c '): # ignore comments
				continue
			if line.startswith('e '): # add an edge, check vertex number are consistent
				parts = line.split(' ')
				u, v = int(parts[1]), int(parts[2])
				if u > vert_num or v > vert_num:
					print('Warning: invalid vertex number found in edge:', line)
				edges.append((u, v))
				
			if line.startswith('p edge'): # parse problem specification
				parts = line.split(' ')
				vert_num = int(parts[2])
				edg_num = int(parts[3])
				vertices = list(range(1, vert_num + 1))

		if edg_num != len(edges):
			print('Warning: number of edges does not match file header: %d != %d' % (len(edges), edg_num))

	return vertices, edges

def write_cnf(cnf, filename):

	variables =  max(map(abs, itertools.chain(*cnf))) # find the maximum number of a variable used
	cnf_str = '\n'.join(map(lambda c: ' '.join(map(str, c)) + ' 0', cnf)) # concatenate clauses into a string

	print('CNF created, it has %d variables and %d clauses' % (variables, len(cnf)))

	with open(filename, 'w') as f:
		f.write('p cnf %d %d\n' % (variables, len(cnf))) # write basic CNF information
		f.write(cnf_str)

def generate_cnf(vertices, edges):
	clauses = []
	
	barvy = int(sys.argv[2])
	
	for k in vertices:
		pole = []
		for o in range(barvy):
			pole.append((k - 1) * barvy + o + 1)
		clauses.append(pole)
		for m in range(barvy):
			for n in range(barvy):
				if (m < n):
					clauses.append([-(m + (k - 1) * barvy + 1), -(n + (k - 1) * barvy + 1)])
	
	for i,j in edges:  # for each edge, both vertices need to have a different color
		for m in range(barvy):
			clauses.append([-((i - 1) * barvy + m + 1), -((j - 1) * barvy + m + 1)])
				
	#print(clauses)
	return clauses

if __name__ == '__main__':
	vertices, edges = read_graph(sys.argv[1])

	print('Number of vertices:', len(vertices))
	print('Number of edges:', len(edges))

	cnf = generate_cnf(vertices, edges)

	write_cnf(cnf, sys.argv[1] + '.cnf')
