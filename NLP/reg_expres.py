import re

sentence = "Some one oppened the door, it was mostlike the Mode she is 32 years old. She came to " \
           "see Dan he is 10"

ages = re.findall(r'\d{1,3}', sentence)
names = re.findall(r'[A-Z][a-z]', sentence)
x = 0

print(ages)
print(names)
