def factorial(n):
  if n < 2:
    return 1
  return n * factorial(n-1)

factorial(1000)

#wont work because python cant go past 1000 increments of recursion