

a_0 = 0
a_1 = 4
a_2 = 9
i = 3
while True:
    a_3 = 4*a_2-5*a_1+2*a_0
    a_0 = a_1
    a_1 = a_2
    a_2 = a_3
    v = -1+3*i+(2**i)
    print(str(i) + ": " + str(a_2) + ": " + str(v))  
    a = input()
    i += 1
    if a == "x":
        break
