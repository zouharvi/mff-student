def end_other(a, b):
  a = a.lower()
  b = b.lower()
  if len(a) > len(b):
    tmp = b
    b = a
    a = tmp
  # b is bigger and has to contain a
  return b[(len(b) - len(a)):] == a

print(end_other('abc', 'abXabc') == True, end='')
