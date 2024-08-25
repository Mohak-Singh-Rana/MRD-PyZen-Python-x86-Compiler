class A:
  def __init__(self,x:str,y:str):
    print(x)
    print(y)
    self.x : str = y
    self.y :str = x
    # self.y:str = x

def main():
  t:str = "Hello"
  t="mine"
  a:A = A(t,"hdsu")
  # print(t)
  print(a.x)
  print(a.y)

if __name__=="__main__":
  main()
