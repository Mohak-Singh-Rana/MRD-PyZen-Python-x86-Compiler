class ShiftReduceParser:

  def __init__(self, name_: str):
    self.srname: str = name_
    a:int =10
  


class LR0Parser(ShiftReduceParser):

  def __init__(self, myname_: str, parentname_: str):
    self.lr0name: str = myname_
    ShiftReduceParser.__init__(self, parentname_)


class CLRParser(ShiftReduceParser):

  def __init__(self, myname_: str, parentname_: str):
    self.clrname: str = myname_
    self.b: int = 2
    ShiftReduceParser.__init__(self, parentname_)
  def print_name_clr(self):
    print("SLR name:")
    print(self.srname)
    print("CLR name:")
    print(self.clrname)


class LALRParser(CLRParser):

  def __init__(self, myname_: str, clrname_: str, srname_: str):
    self.lalrname: str = myname_
    CLRParser.__init__(self, clrname_, srname_)

  def print_name(self):
    print("SLR name:")
    print(self.srname)
    print("CLR name:")
    print(self.clrname)
    print("LALR name:")
    print(self.lalrname)


def main():
  obj1: LALRParser = LALRParser("LALR1", "CLR1", "Shift-Reduce1")
  obj1.print_name()
  obj2: CLRParser = CLRParser("CLR2", "Shift-Reduce2")
  obj2.print_name_clr()
  


if __name__ == "__main__":
  main()
