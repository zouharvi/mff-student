def xyz_there(str):
  return (str.count('xyz') - str.count('.xyz') >= 1)

print(xyz_there('xyz.abc') == True, end='')