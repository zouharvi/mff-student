def front_times(str, n):
  front = str[0:3]
  a = ''
  for i in range(n):
    a += front
  return a

print(front_times('Chocolate', 2) == 'ChoCho', end='')
