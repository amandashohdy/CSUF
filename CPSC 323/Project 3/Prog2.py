'''
Project 3
Problem 6



Grammar:
  E -> E + T
  E -> E - T
  E -> T
  T -> T * F
  T -> T / F
  T -> F
  F -> (E)
  F -> i 
'''

rules = {
  "1" : ["E", "E+T"],
  "2" : ["E", "E-T"],
  "3" : ["E", "T"],
  "4" : ["T", "T*F"],
  "5" : ["T", "T/F"],
  "6" : ["T", "F"],
  "7" : ["F", "(E)"],
  "8" : ["F", "i"]
}

parsingTable = {
  "0" : {"i" : "S5", 
         "(" : "S4",
         "+" : "S6",
         "E" : "1", 
         "T" : "2", 
         "F" : "3"     },
  "1" : {"+" : "S6",
         "-" : "S7",
         "$" : "ACCT"},
  "2" : {"+" : "R3",
         "-" : "R3",
         "*" : "S8",
         "/" : "S9",
         ")" : "R3",
         "$" : "R3"  },
  "3" : {"+" : "R6",
         "-" : "R6",
         "*" : "R6",
         "/" : "R6",
         ")" : "R6",
         "$" : "R6"  },
  "4" : {"i" : "S5",
         "(" : "S4",
         "E" : "10",
         "T" : "2",
         "F" : "3"     },
  "5" : {"+" : "R8",
         "-" : "R8",
         "*" : "R8",
         "/" : "R8",
         ")" : "R8",
         "$" : "R8"  },
  "6" : {"i" : "S5",
         "(" : "S4",
         "T" : "11",
         "F" : "3"     },
  "7" : {"i" : "S5",
         "(" : "S4",
         "T" : "12",
         "F" : "3"     },
  "8" : {"i" : "S5",
         "(" : "S4",
         "F" : "13",   },
  "9" : {"i" : "S5",
         "(" : "S4",
         "F" : "14"    },
  "10": {"+" : "S6",
         "-" : "S7",
         ")" : "S15" },
  "11": {"+" : "R1",
         "-" : "R1",
         "*" : "S8",
         "/" : "S9",
         ")" : "R1",
         "$" : "R1"  },
  "12": {"+" : "R2",
         "-" : "R2",
         "*" : "S8", 
         "/" : "S9",
         ")" : "R2",
         "$" : "R2"  },
  "13": {"+" : "R4",
         "-" : "R4",
         "*" : "R4",
         "/" : "R4",
         ")" : "R4",
         "$" : "R4"  },
  "14": {"+" : "R5",
         "-" : "R5",
         "*" : "R5",
         "/" : "R5",
         ")" : "R5",
         "$" : "R5"  },
  "15": {"+" : "R7",
         "-" : "R7",
         "*" : "R7",
         "/" : "R7",
         ")" : "R7",
         "$" : "R7"  }
}

string = input("Enter a string ending in $: ")

stack = ["$"]

print(f"{'input' : <15}", f"{'stack' : <20}")
print("--------------------------------")
print(f"{string : <15}", f"{str(stack) : <20}")

stack.append("0")
print(f"{string : <15}", f"{str(stack) : <20}")

while (len(string) > 0) :
  try :
    # shift rule
    if (parsingTable[stack[-1]][string[0]][0] == "S") :
      newState = parsingTable[stack[-1]][string[0]][1:]
      stack.append(string[0])
      stack.append(newState)
      string = string[1:]
  
    # reduce rule 
    elif (parsingTable[stack[-1]][string[0]][0] == "R") :
      rule = parsingTable[stack[-1]][string[0]][1:] 
      while (stack[-1] != rules[rule][1][0]) :
        stack.pop()
      stack.pop()
      state = stack[-1]
      stack.append(rules[rule][0])
      stack.append(parsingTable[state][rules[rule][0]])

  # KeyError results in a rejected string
  except KeyError :
    print("String Rejected")
    break
    
  print(f"{string : <15}", f"{str(stack) : <20}")
  
  #accepted state
  if (stack[-1] == "1" and string == "$") :
    print("String Accepted")
    string = ""
  
input("Press Enter to Close...")