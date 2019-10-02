def count_code(str):
  count = 0
  for i in range(len(str)-3):
    if str[i] == 'c' and str[i+1] == 'o' and str[i+3] == 'e':
      count += 1
      
  return count

print(count_code('cozexxcope') == 2, end='')
