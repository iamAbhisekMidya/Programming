import math
x,y=[int(a) for a in (input("Enter two numbers seperate by space: ")).split()]
print("Gcd of two numbers {} and {} is ".format(x,y),math.gcd(x,y))
print("Lcm of two numbers {} and {} is ".format(x,y),math.lcm(x,y))
