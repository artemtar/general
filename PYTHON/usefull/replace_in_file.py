with open('file.txt', 'r') as file :
  filedata = file.read()

# Replace the target string
filedata = filedata.replace('`', '\'')

# Write the file out again
with open('file.txt', 'w') as file:
  file.write(filedata)