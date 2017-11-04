import sys
sys.path
import nltk

from nltk.tokenize import sent_tokenize, word_tokenize


just_a_simple_text = "Hello, long time no see. Mr. Anderson, please, follow the red rabbit. Whatever."

l = sent_tokenize (just_a_simple_text)

print (l)
