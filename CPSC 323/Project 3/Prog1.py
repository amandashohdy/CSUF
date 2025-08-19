'''
Project 3
Problem 4



Grammar:
  S  -> F = E
  E  -> F!E'
  E' -> &TE'
  E' -> %TE'
  E' -> ε
  F  -> tF'
  F  -> fF'
  F' -> <TF'
  F' -> >TF'
  F' -> ε
  T  -> (E)
  T  -> t
  T  -> f
'''

parsingTable = {
  "S"  : {"t" : "F=E",
          "f" : "F=E",
          "$" : "ACCEPT"},
  "E"  : {"t" : "F!E'", 
          "f" : "F!E'",},
  "E'" : {"&" : "&TE'",
          "%" : "%TE'",
          ")" : "ε",
          "$" : "ε"},
  "F"  : {"t" : "tF'", 
          "f" : "fF'"},
  "F'" : {"=" : "ε",
          "!" : "ε",
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

stack.append("S")
print(f"{string : <15}", f"{str(stack) : <20}")

while (len(string) > 0) :
  try :
    # if current symbol in stack matches current symbol in input string
    if (stack[-1] == string[0]) :
      stack.pop()              # pop the top of the stack
      string = string[1:]      # remove character from input string 
      print(f"{string : <15}", f"{str(stack[0:]) : <20}")
    else :
      # temp = rule at [top of stack][current symbol in input string]
      temp = parsingTable[stack[-1]][string[0]]
      stack.pop()              # pop the top of the stack 
      while (len(temp) != 0) :
      # push rule into the stack 
        if (temp[-1] == "'") :
          stack.append(temp[-2:])
          temp = temp[:-2]
        else :
          if (temp[-1] != "ε") :
            stack.append(temp[-1])
          temp = temp[:-1]
    
    print(f"{string : <15}", f"{str(stack[0:]) : <20}")

  # KeyError results in a rejected string 
  except KeyError :
    print("String rejected")
    break

  if (len(stack) == 0 and len(string) == 0) : 
    print("String accepted")

input("Press Enter to Close...")
