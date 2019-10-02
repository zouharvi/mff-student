def array123(nums):
  joined = '|'.join(str(x) for x in nums)
  return ('1|2|3' in joined)


print(array123([1, 1, 2, 3, 1]) == True, end='')
