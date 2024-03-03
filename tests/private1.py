for i in range(5):
    print("Iteration", i)

count = 0
while count < 5:
    print("Count is", count)
    count += 1

num = 10
while num > 0:
    print(num)
    num -= 1
else:
    print("Loop finished.")

for num in range(10, 15):
    print(num)
else:
    print("Loop finished.")

num = 7
if num % 2 == 0:
    print("Even")
else:
    print("Odd")

score = 85
if score >= 90:
    print("A")
elif score >= 80:
    print("B")
elif score >= 70:
    print("C")
else:
    print("Fail")

for i in range(3):
    print("Outer loop iteration", i)
    for j in range(2):
        print("Inner loop iteration", j)


a = 10
b = 20
if a > b:
    print("a is greater than b")
else:
    print("b is greater than a")

for letter in 'Python':
    print('Current Letter :', letter)

for alpha in [1,2,3,4,5,6] :
    print("""alpha""", alpha, alpha + 1, alpha*2)
