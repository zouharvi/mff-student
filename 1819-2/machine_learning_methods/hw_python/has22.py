def has22(nums):
  for i in range(len(nums)-1):
    if nums[i] == 2 and nums[i+1] == 2:
      return True
  return False

print(has22([1, 2, 1, 2]) == False, end='')