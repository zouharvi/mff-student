def sum67(nums):
  beg_6 = False
  count = 0
  for a in nums:
    if a == 6:
      beg_6 = True
      continue
    if a == 7 and beg_6:
      beg_6 = False
      continue
    if not beg_6:
      count += a
  return count

print(sum67([1, 2, 2, 6, 99, 99, 7]) == 5, end='')