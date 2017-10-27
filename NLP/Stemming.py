from nltk.stem import PorterStemmer
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords

ps = PorterStemmer()

list_simular_words = ["Artem", "Artemed", "Artemedly","Artemization", "Arteming"]
for w in list_simular_words:
    print(ps.stem(w))

example_sent = "wheelchair BEST SENTENCE EVER ITS AS GOOD AS a babies bottom licking an orange watermellon"



list_of_words = word_tokenize(example_sent)
print("stemfull and noisfull:")
print(list_of_words)

#creating stop words to remove from sentence
list_stop_words = stopwords.words("english")
#removing noise
list_of_words_noisless = []
for w in list_of_words:
    if w not in list_stop_words:
        list_of_words_noisless.append(w)
print("stemfull and noisless:")
print(list_of_words_noisless)

#getting stem of words

list_of_words_noisless_and_stemmed = []
for w in list_of_words_noisless:
    list_of_words_noisless_and_stemmed.append(ps.stem(w))
print("stemless and noisless:")
print(list_of_words_noisless_and_stemmed)
