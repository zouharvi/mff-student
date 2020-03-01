#!/usr/bin/env python3

import sys

if len(sys.argv) != 2:
    raise Exception('Wrong number of arguments')

with open(sys.argv[1], 'r') as f:
    refInput = [x.rstrip('\n').split('.') for x in f.readlines()]

for node in refInput:
    if len(node) != 2:
        raise Exception('Malformed input file')

class Node:
    def __init__(self, name):
        self.children = set()
        self.name = name

    def add(self, child):
        self.children.add(child)
    
    def __str__(self):
        out = f'{self.name}'
        if len(self.children) == 0:
            return out
        else:
            return out + '(' + ','.join([str(x) for x in self.children]) + ')'

# tree contains only nodes, which have a parent or a root
tree = {}

# find root
for node in refInput:
    if len(node[1]) == 0:
        if len(tree) != 0:
            raise Exception("More than one root")
        else:
            tree[node[0]] = Node(node[0])

if len(tree) == 0:
    raise Exception("No root found")

# remove root
for key in tree:
    root = tree[key]
    refInput.remove([key, ''])

# find multiple parents
children = {}
for node in refInput:
    child = node[0]
    parent = node[1]
    if (child in children) and (parent != children[child]):
        raise Exception(f'Multiple parents of {child}')
    children[child] = parent

# construct the tree
for x in range(len(refInput)):
    toremove = []
    for node in refInput:
        child = node[0]
        parent = node[1]
        if parent in tree:
            if child in tree:
                raise Exception(f'A cycle found')
            tree[child] = Node(child)
            tree[parent].add(tree[child])
            toremove.append(node)
            
    if len(toremove) == 0:
        break # no change, we are done
    for node in toremove:
        refInput.remove(node)

if len(refInput) != 0:
    raise Exception(f'No path from {refInput[0][1]} to root')

print(root)