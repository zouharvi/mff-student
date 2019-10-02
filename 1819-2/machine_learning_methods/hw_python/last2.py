def last2(str):
  back = str[(len(str)-2):]
  nos = 0
  for i in range(0, len(str)-2):
    if str[i:(i+2)] == back:
      nos += 1
  return nos

print(last2('hixxhi') == 1, end='')
