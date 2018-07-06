import re

text_to = '''


abcdefghijklmnopqurtuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
bal@gamBil.com 1234567890
bal.sassa@gamBil.com
Ha HaHa
MetaCharacters (Need to be escaped):
. ^ $ * + ? { } [ ] \ | ( )
coreyms.com
321-555-4321
123.555.1234
123*555*1234
800-555-1234
900-555-1234
Mr. Schafer
Mr Smith
Ms Davis
Mrs. Robinson
Mr. T
cat mat bat
'''

pattern = re.compile(r'\d{3}[-/.]\d{3}[/.-]\d{2,4}')
p1 = re.compile(r'[^b]at')
p2 = re.compile(r'\bMr\.?\s\w*\b')
p3 = re.compile(r'[a-z.]+@\w{2,}\.[a-z]+')

sublist = p1.sub('new', text_to)

print(sublist)

match = p3.findall(text_to)

for m in match:
    print(m)

# with open('data.txt', 'r', encoding='utf-8') as f:
#
#     content = f.read()
#     m = pattern.findall(content)
#     for item in m:
#         print(item)