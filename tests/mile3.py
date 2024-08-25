def foo(a : int)->int:
  return (a+1)

def main():
  data : list[int] = [1,2,3,4,5]
  print(len(data))
  x:str = "hello"
  #y: str = x
  print(x)
  a : int = 5
  z:int = foo(a)
  print(z)

if __name__ == "__main__":
  main()
