#!/usr/bin/python
import re

sentence = "Some one oppened the door, it was mostlike the Mode she is 32 years old. She came to " \
           "see Dan he is 10"

# ages = re.findall(r'\d{1,3}', sentence)
# names = re.findall(r'[A-Z][a-z]', sentence)
# x = 0
#
# print(ages)
# print(names)
#
# list_words = re.split(r"""(\s*)""", sentence)
# print(list_words)
# print(re.split(r"""(s*)""", sentence))
#print(re.split(r'([b-f][d-f])', 'abdEfghijklmnopqrstucv', re.M | re.I))
#print(re.findall(r'\d{2,3}\s\w+\s\w*\.', 'hello 23 main st. whateger'))
#chunk = r"""chunk: {\d{1,3}}"""
#print(chunk)

import urllib

try:
    import urllib.request
except:
    pass

sites = "google cnn youtube 9gag".split()
pattern = re.compile(r'<title>+.*</title>+', re.I | re.M)

for s in sites:
    print("Searching: " + s)
    try:
        u = urllib.urlopen("http://" + s + ".com")
    except:
        u = urllib.request.urlopen("http://" + s + ".com")
    text = u.read()
    title = re.findall(pattern, str(text))
    print(title[0])