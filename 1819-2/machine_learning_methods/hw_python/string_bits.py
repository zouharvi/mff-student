def string_bits(str):
  flip = True
  a = ''
  for c in str:
    if flip:
      a += c
    flip = not flip
  return a

print(string_bits('Hello') == 'Hlo', end='')
