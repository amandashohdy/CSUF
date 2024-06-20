'''
Project 2
Problem 16



Grammar:
  E  -> F!E'
  E' -> &TE'
  E' -> %TE'
  E' -> ε
  F  -> tF
  F  -> fF
  F' -> <TF'
  F' -> >TF'
  F' -> ε
  T  -> (E)
  T  -> t
  T  -> f
'''

parsingTable = {
  "E"  : {"t" : "F!E'", 
          "f" : "F!E'",
          "$" : "ACCEPT"},
  "E'" : {"&" : "&TE'",
          "%" : "%TE'",
          ")" : "ε",
          "$" : "ε"},
  "F"  : {"t" : "tF'", 
          "f" : "fF'"},
  "F'" : {"!" : "ε",
          "<" : "<TF'",
          ">" : ">TF'",
          "$" : "ε"},
  "T"  : {"t" : "t",
          "f" : "f",
          "(" : "(E)"}
}

string = input("Enter a string ending in $: ")

stack = ["$"]

print(f"{'input' : <15}", f"{'stack' : <20}")
print("--------------------------------")
print(f"{string : <15}", f"{str(stack) : <20}")

stack.append("E")
print(f"{string : <15}", f"{str(stack) : <20}")

while (len(string) > 0) :
  try :
    if (stack[-1] == string[0]) :
      stack.pop()
      string = string[1:]
      print(f"{string : <15}", f"{str(stack[0:]) : <20}")
    else :
      temp = parsingTable[stack[-1]][string[0]]
      stack.pop()
      while (len(temp) != 0) :
        if (temp[-1] == "'") :
          stack.append(temp[-2:])
          temp = temp[:-2]
        else :
          if (temp[-1] != "ε") :
            stack.append(temp[-1])
          temp = temp[:-1]
    
    print(f"{string : <15}", f"{str(stack[0:]) : <20}")

  except KeyError :
    print("String rejected")
    break

  if (len(stack) == 0 and len(string) == 0) : 
    print("String accepted")

input("Press Enter to Close...")