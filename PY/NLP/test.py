from nltk.tokenize import sent_tokenize
import sys
sys.path 
#nltk.download()

# tokenizing - word tokenizers, sentence ets
# corpara - body of text, jornal, presentation
# lexicon - words and their meaning

import re

rstr = "what whatb"

reg = re.compile("[\w]+[.]*")

print(re.findall(reg, rstr))
