def sum13(nums):
  count = 0
  skip = False
  for a in nums:
    if skip:
      skip = False
      continue
    if a == 13:
      skip = True
    else:
      count += a
  return count

print(sum13([1, 2, 2, 1, 13]) == 6, end='')