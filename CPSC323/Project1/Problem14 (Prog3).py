'''
Project 1
Question 14

'''

reservedWords = { "cin>>", "for", "int", "while"}
operators = { "+", "-", "*", "/", "++", "--"}
special = {">", "=", ";", "(", ")", ">=", ",", "{", "}"}

cont = "y"   # VARIABLE cont - continue?
while (cont == "y" or cont == "Y") :
  statement = input("Enter a Statement: \n  ")

  while (len(statement) != 0) :
    
    valid = False    # lexeme is invalid unless proven otherwise
    # pass whitespace
    if (statement[0] == " ") : 
      statement = statement[1:]
  
  # RESERVED WORDS
    if (statement[0].isalpha()) :
      # check "cin>>" and "while"
      if (statement[0:5] in reservedWords) :
        print("\t",f"{statement[0:5] : <15}", f"{'reserved word' : <20}")
        statement = statement[5:]  # remove processed input from statement 
        valid = True
      # check "for" and "int"
      elif (statement[0:3] in reservedWords) :
        print("\t",f"{statement[0:3] : <15}", f"{'reserved word' : <20}")
        statement = statement[3:]  # remove processed input from statement 
        valid = True
  # IDENTIFIERS
      else :
        identifierIndex = 1
        for index in range(1, len(statement)) :
          if statement[index].isalnum() :
            identifierIndex += 1
          else :
            break
        print("\t",f"{statement[0:identifierIndex] : <15}", f"{'identifier' : <20}")
        statement = statement[identifierIndex:]  # remove processed input from statement 
        valid = True          
  
  # SPECIAL SYMBOLS
    # check ">="
    elif (statement[0:2] in special) :
      print("\t",f"{statement[0:2] : <15}", f"{'special symbol' : <20}")
      statement = statement[2:]   # remove processed input from statement 
      valid = True
    # check > = ; ( ) ,
    elif (statement[0] in special) :
      print("\t",f"{statement[0] : <15}", f"{'special symbol' : <20}")
      statement = statement[1:]   # remove processed input from statement 
      valid = True

  # NUMBERS AND OPERATORS
    elif (statement[0].isdigit() or statement[0] == "+" or statement[0] == "-") :
    # NUMBERS
      if (statement[1].isdigit()) :
        numberIndex = 1
        for index in range(1, len(statement)) :
          if statement[index].isdigit() :
            numberIndex += 1
          else :
            break
        print("\t",f"{statement[0:numberIndex] : <15}", f"{'number' : <20}")
        statement = statement[numberIndex:]  # remove processed input from statement 
        valid = True
    # OPERATORS
      #check "++" and "--"
      elif (statement[0:2] in operators) :
        print("\t", f"{statement[0:2] : <15}", f"{'operator' : <20}")
        statement = statement[2:]  # remove processed input from statement 
        valid = True
      elif (statement[0] in operators) :
        print("\t", f"{statement[0] : <15}", f"{'operator' : <20}")
        statement = statement[1:]  # remove processed input from statement 
        valid = True

    # INVALID
    if (not valid) :
      # if there are more lexemes after
      if (statement.find(" ") != -1) :
        print("\t",f"{statement[0:statement.find(' ')] : <15}", f"{'invalid' : <20}")
        statement = statement[statement.find(" "):]  # remove processed input 
      # if this is the last lexeme
      else :
        print("\t", f"{statement[0:] : <15}", f"{'invalid' : <20}")
        statement = ""   # remove processed input from statement
  
  cont = input("Continue? (y/n): ")
  print()
