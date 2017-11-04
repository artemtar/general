from nltk.corpus import movie_reviews
import random
import nltk

#doc = [(list(movie_reviews.words(fileid)), category)
#         for category in movie_reviews.categories()
#         for fileid in movie_reviews.fileids(category)]

##same

docs = []
for category in movie_reviews.categories():
    for fileid in movie_reviews.fileids(category):
        docs.append((list(movie_reviews.words(fileid)), category))
random.shuffle(docs)
print(docs[1])
#Words distribution
words = []
for w in movie_reviews.words():
    words.append(w.lower())
words = nltk.FreqDist(words)
popular_words = list(words.keys())[:3000]

print(len(docs), "size")
#looling for set of common words
def find_pop(document):
    set_document = set(document)
    #checking if words in the most frequents words
    ispopular = {}
    # for w in set_document:
    #     if w in popular_words:
    #         ispopular[w] = True
    #     else: ispopular[w] = False
    # same thing different way
    for w in set_document:
        ispopular[w] = (w in popular_words)
    return ispopular

#print(find_pop(movie_reviews.words("neg/cv000_29416.txt")))
# data = []
# for (rev, category) in docs:
#     data.append((find_pop(rev), rev))
data = [(find_pop(rev), category) for (rev, category) in docs]
train_set = tuple(data[:1900])
testing_set = tuple(data[1900:])
print(len(data))
#prepearing classifier
nbcClassifier = nltk.NaiveBayesClassifier.train(train_set)
#checking accuracy
result = nltk.classify.accuracy(nbcClassifier, testing_set)
print(result*100)
nbcClassifier.show_most_informative_features(20)