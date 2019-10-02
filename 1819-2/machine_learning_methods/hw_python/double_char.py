def double_char(str):
  a = ''
  for c in str:
    a += c + c
  return a

print(double_char('Hi-There')  == 'HHii--TThheerree', end='')
