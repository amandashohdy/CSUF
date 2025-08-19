'''
Project 1
Problem 13

'''

# READ data from file
fileName = "input.txt"
file = open(fileName, "r")
content = file.read()
file.close()

# Variable to store the output
output = []

# CONTINUE processing data until content string is empty 
while len(content) != 0:

    if content[0:2] == "//":
        newLineIndex = 0
        for i in range(2, len(content)):
            if content[i] == "\n":  
                newLineIndex = i    
                break
        if newLineIndex == 0:  
            newLineIndex = len(content) - 1  
        content = content[newLineIndex + 1:]  

    elif content[:5] == "cin>>":
        output.append("cin>>")
        content = content[5:]

    elif content[0].isalnum() or content[0] == '_':
        endIndex = 1
        for i in range(1, len(content)):
            if not content[i].isalnum() and content[i] != '_':  
                endIndex = i
                break
        output.append(content[0:endIndex])  
        content = content[endIndex:]  

    else:
        if content[0] == ';':  
            output.append(";")  
            output.append("\n")
        elif content[0] not in [" ", "\n"]:
            output.append(content[0])  
        content = content[1:]  

with open("output.txt", "w") as outputFile:
    outputFile.write(" ".join(output).replace(" \n ", "\n"))

with open("output.txt", "r") as output_file:
    output_content = output_file.read()

print(output_content)

