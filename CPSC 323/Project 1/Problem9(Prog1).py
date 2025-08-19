'''
Project 1
Problem 9

'''

# L = (a|b)* ba*a 

string = input("Enter a string ending in $: ")
index = 0

currentState = "A"
while (string[index] != '$') :
  if   (currentState == "A" and string[index] == 'a') :
    currentState = "B"
  elif (currentState == "A" and string[index] == 'b') :
    currentState = "C"
  #                     "B" and                  'a'  : B
  elif (currentState == "B" and string[index] == 'b') : 
    currentState = "C"
  elif (currentState == "C" and string[index] == 'a') :  
    currentState = "D"
  #                     "C" and                  'b'  : C
  #                     "D" and                  'a'  : D
  elif (currentState == "D" and string[index] == 'b') : 
    currentState = "C"
  
  index += 1

if (currentState == "D") :
  print(string, "YES")
else :
  print(string, "NO")

print()
input("Press Enter to Close...")