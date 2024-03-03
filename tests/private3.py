a = 5
b = 2
c = 3.5

d = a * b / c + 7.2 - 5 * 3.6 + 4 / 2.5
e = b - c / a * 9.8 + 6.7 / 4 - 2.1
f = c + a * b - 5.3 / 2.1 + 8.9 - 6.4
g = a / b + c * 4.7 - 8.2 / 3.9 + 7.4
h = b * c - a / 2.3 + 9.4 / 5.6 - 3.8

d = a + b - c
e = a * b / c % 2
f = a ** b
g = b // a
h = c * (a + b)
i = a / b
j = a % b

d += e
e -= f
f *= g
g /= h
h **= i
i //= j
j %= a

k = True
l = False

m = not k
n = k and l
o = k or l
p = k is not l
q = k is l
r = k in [a, b, c]

s = a > b
t = b < c
u = c == a
v = a != b
w = b >= c
x = c <= a

s &= t
t |= u
u ^= v
v <<= w
w >>= x

result = ((a + b) * c / 2) + (a ** b) - ((a // b) % c)

result2 = ((((a + b) * c) ** 2) / (a % b)) + (b - c) + ((a * b) / (c ** 2)) - ((a // b) % c)
