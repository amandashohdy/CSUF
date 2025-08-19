''' 
Project 1
Question 13

'''

# READ data from file
fileName = "Problem13_Input.txt"
file = open(fileName, "r")
content = file.read()
file.close() 

# CONTINUE processing data until content string is empty 
while (len(content) != 0) :

  # COMMENTS are disregarded 
  if (content[0:2] == "//") :
    newLineIndex = 0
    for i in range(2, len(content)) :
      if (content[i] == "\n") :  # if a newline character is encountered 
        newLineIndex = i    # save newline character index
        break
    if (newLineIndex == 0) :  # if the end of content is reached without a newline
      newLineIndex = len(content) - 1  # newLineIndex is the last index
    content = content[newLineIndex + 1:]   # remove processed input 

  # IDENTIFIERS AND RESERVED WORDS
  elif (content[0].isalnum()) :
    if (content[0:5] == "cin>>") :
      print(content[0:5], end=" ")
      content = content[5:]
    else:
      endIndex = 1
      for i in range(1, len(content)) :
        if (not content[i].isalnum()) :  # find end of word
          endIndex = i
          break
      print(content[0:endIndex], end=" ")  # output separated by space 
      content = content[endIndex:]  # remove processed input 
    
  # OPERATORS AND SPECIAL SYMBOLS
  else :
    # SEMICOLON
    if (content[0] == ";") :  
      print(";")    # semicolor results in a newline
    # OTHER SYMBOLS
    elif (content[0] != " " and content[0] != "\n") :
      print(content[0], end=" ")    # output separated by space
    content = content[1:]  # remove processed input
