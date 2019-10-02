def string_times(str, n):
  a = ''
  for i in range(n):
    a += str
  return a

print(string_times('Hi', 2) == 'HiHi', end='')
