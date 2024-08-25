class testing():
  def loop_func1(n:int)->int:
    i:int
    j:int
    for i in range(3,8):
      a : float = n
      for j in range(10):
        b : int = 5
        if(j==5):
          b += 1
          break
      a = a + 2
      if(a < 7):
        break
    return j

  def loop_func2(n:int)->int:
    k:int
    l:int
    for k in range(3,8):
      c : float = n
      for l in range(10):
        d : int = 5
        if(j==5):
          d += 1
          continue
      c = c + 2
      if(c < 7):
        break
    return l 

  def loop_func3(n:int)->int:
    m:int
    o:int
    while(m):
      e : float = n
      while(o):
        f : int = 5
        if(j==5):
          f += 1
          break
      else:
        o = o + 1
      e = e + 2
      if(e < 7):
        break
      e=2
    return o

def main():
  obj : testing = testing()
  obj.loop_func1(5)
  obj.loop_func2(5)
  obj.loop_func3(6)


if __name__ == "__main__":
  main()
