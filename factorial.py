n = int(input('enter an number'))
factorial = 1
for i in range(1, n + 1):
    factorial *= i
print('Factorial of %d is %d' % (n, factorial))
