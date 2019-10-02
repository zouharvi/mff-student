def string_match(a, b):
  count = 0
  for i in range(min(len(a), len(b))-1):
    if a[i:(i+2)] == b[i:(i+2)]:
      count += 1
  return count

print(string_match('xxcaazz', 'xxbaaz')  == 3, end='')
