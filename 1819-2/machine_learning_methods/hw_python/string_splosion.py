def string_splosion(str):
  a = ''
  for i in range(1,len(str)+1):
    a += str[0:i]
  return a

print(string_splosion('Code') == 'CCoCodCode', end='')