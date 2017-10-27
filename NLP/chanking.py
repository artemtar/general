import nltk
from nltk.corpus import state_union
from nltk.tokenize import PunktSentenceTokenizer, word_tokenize

trainer = state_union.raw("2005-GWBush.txt")
sample = state_union.raw("2006-GWBush.txt")

pm = PunktSentenceTokenizer(trainer)
sample_tokenized = pm.tokenize(sample)
sample_tagged = []
for s in sample_tokenized:
    words = word_tokenize(s)
    sample_tagged.append(nltk.pos_tag(s))
print(sample_tagged)