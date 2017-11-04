from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

sentence = "this is a new sentens, from which i want to remove all noise"
noise = stopwords.words("english")
print(noise)
sentence_words = word_tokenize(sentence)
filtered_sentence = []
for w in sentence_words:
    if w not in noise:
        filtered_sentence.append(w)
print(filtered_sentence)
print("different way , same staff")
filtered_sentence2 = [w for w in sentence_words if not w in noise]
print(filtered_sentence2)
