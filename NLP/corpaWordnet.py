from nltk.corpus import wordnet as wn


synonym = wn.synsets("dogs")
#lem = wn.sy
print(synonym)
print(synonym[0].lemmas())

#compare

w1 = wn.synsets("octopus")[0]
w2 = wn.synsets("cactus")[0]
print(w1.wup_similarity(w2))


