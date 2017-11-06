from nltk.corpus import movie_reviews
import random
import nltk
import pickle
from nltk.classify import ClassifierI
#from statistics import mode
from nltk.classify.scikitlearn import SklearnClassifier
from sklearn.naive_bayes import MultinomialNB, BernoulliNB
from sklearn.linear_model import LogisticRegression, SGDClassifier
from sklearn.svm import SVC, LinearSVC, NuSVC

#doc = [(list(movie_reviews.words(fileid)), category)
#         for category in movie_reviews.categories()
#         for fileid in movie_reviews.fileids(category)]

##same

docs = []
for category in movie_reviews.categories():
    for fileid in movie_reviews.fileids(category):
        docs.append((list(movie_reviews.words(fileid)), category))
#
# f_doc = open("Data/words_review.pickle", "wb")
# pickle.dump(docs, f_doc)
# f_doc.close()
# f_doc = open("Data/words_review.pickle", "rb")
# docs = pickle.load(f_doc)

random.shuffle(docs)

#Words distribution
words = []
for w in movie_reviews.words():
    words.append(w.lower())
words = nltk.FreqDist(words)
popular_words = list(words.keys())[:3000]

with open("Data/word_frequency_reveiw.pickle", "wb") as wfr:
    pickle.dump(popular_words, wfr)

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

with open("Data/trainingData.pickle", "wb") as f:
    pickle.dump(train_set, f)
    pickle.dump(testing_set, f)
    f.close()

#prepearing classifier
nbcClassifier = nltk.NaiveBayesClassifier.train(train_set)
nbcClassifier.train(train_set)
print("nlk naive accuracy: ", nltk.classify.accuracy(nbcClassifier, testing_set))

multinomialNB_class = SklearnClassifier(MultinomialNB())
multinomialNB_class.train(train_set)
print("multibinomial accuracy: ", nltk.classify.accuracy(multinomialNB_class, testing_set))

bernulli_class = SklearnClassifier(BernoulliNB())
bernulli_class.train(train_set)
print("bersnulli accuracy: ", nltk.classify.accuracy(bernulli_class, testing_set))

SGD_class= SklearnClassifier(SGDClassifier())
SGD_class.train(train_set)
print("SGD accuracy: ", nltk.classify.accuracy(SGD_class, testing_set))

logist_regres_class = SklearnClassifier(LogisticRegression())
logist_regres_class.train(train_set)
print("logistic regression accuracy: ", nltk.classify.accuracy(logist_regres_class, testing_set))

SVC = SklearnClassifier(SVC())
SVC.train(train_set)
print("SVC accuracy: ", nltk.classify.accuracy(SVC, testing_set))

nuSVC = SklearnClassifier(NuSVC())
nuSVC.train(train_set)
print("nuSVC accuracy: ", nltk.classify.accuracy(nuSVC, testing_set))

linearSVC = SklearnClassifier(LinearSVC())
linearSVC.train(train_set)
print("linear SVC accuracy: ", nltk.classify.accuracy(linearSVC, testing_set))

print("Lia said:")

text = "In bas, I liked it so much, would see it again"
print(text)
print("This review is:")
print(nbcClassifier.classify(find_pop(text)))
print("Lia said:")

text = "Mean girls is a shitty movie, and would never see it again, waste of time"
print(text)
print("This review is:")
print(nbcClassifier.classify(find_pop(text)))
#checking accuracy
# result = nltk.classify.accuracy(nbcClassifier, testing_set)
# print(result*100)
# nbcClassifier.show_most_informative_features(20)