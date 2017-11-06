from nltk.corpus import movie_reviews
from nltk.tokenize import word_tokenize
import random
import nltk
import pickle
from nltk.classify import ClassifierI
from statistics import mode
from nltk.classify.scikitlearn import SklearnClassifier
from sklearn.naive_bayes import MultinomialNB, BernoulliNB
from sklearn.linear_model import LogisticRegression, SGDClassifier
from sklearn.svm import SVC, LinearSVC, NuSVC

#agregative classifier based on every classfier evoked before
class ClassifiersVoting(ClassifierI):
    def __init__(self, *classifiers):
        self._classifiers = classifiers
    def classify(self, featureset):
        votes = []
        for clas in self._classifiers:
            vote = clas.classify(featureset)
            votes.append(vote)
        return mode(votes)
    def confidence(self, parameters):
        votes = []
        for clas in self._classifiers:
            vote = clas.classify(parameters)
            votes.append(vote)
        #count confidence
        most = votes.count(mode(votes))
        return most / len(votes)

words = [] # all words for feature set
#creating pool of review for tranning

# J  = adjective, R = adverb, V = verb
allowed_types = ["J", "R", "V"]

doc = [(list(movie_reviews.words(fileids)), category)
       for category in movie_reviews.categories()
       for fileids in movie_reviews.fileids(category)]

with open("OpinionClassification/positive.txt", 'r') as pos:
    for line in pos:
        sentence = word_tokenize(line)
        doc.append((sentence, "pos"))
        for w in sentence:
            words.append(w.lower())

with open("OpinionClassification/negative.txt", 'r') as neg:
    for line in neg:
        sentence = word_tokenize(line)
        doc.append((sentence, "neg"))
        for w in sentence:
            words.append(w.lower())


for w in movie_reviews.words():
    words.append(w.lower())
words = nltk.FreqDist(words)
popular_words = list(words.keys())[:4500]

with open("Data/word_frequency_reveiw.pickle", "wb") as wfr:
    pickle.dump(popular_words, wfr)

#looling for set of common words, futureset
def find_pop(document):
    set_document = set(document)
    #checking if words in the most frequents words
    ispopular = {}
    for w in set_document:
        ispopular[w] = (w in popular_words)
    return ispopular

data = [(find_pop(rev), category) for (rev, category) in doc]
print("future set length: ", len(data))

random.shuffle(data)#shufle for training

train_set = tuple(data[:10500])
testing_set = tuple(data[10500:])

with open("Data/trainingData.pickle", "wb") as f:
    pickle.dump(train_set, f)
    pickle.dump(testing_set, f)
    f.close()

#prepearing classifier
nbcClassifier = nltk.NaiveBayesClassifier.train(train_set)
nbcClassifier.train(train_set)
print("nlk naive accuracy: ", nltk.classify.accuracy(nbcClassifier, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/nbcClassifier.pickle", "wb") as f:
    pickle.dump(nbcClassifier, f)


multinomialNB_class = SklearnClassifier(MultinomialNB())
multinomialNB_class.train(train_set)
print("multibinomial accuracy: ", nltk.classify.accuracy(multinomialNB_class, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/multinomialNB_class.pickle", "wb") as f:
    pickle.dump(multinomialNB_class, f)

bernulli_class = SklearnClassifier(BernoulliNB())
bernulli_class.train(train_set)
print("bersnulli accuracy: ", nltk.classify.accuracy(bernulli_class, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/bernulli_class.pickle", "wb") as f:
    pickle.dump(bernulli_class, f)

SGD_class= SklearnClassifier(SGDClassifier())
SGD_class.train(train_set)
print("SGD accuracy: ", nltk.classify.accuracy(SGD_class, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/SGD_class.pickle", "wb") as f:
    pickle.dump(SGD_class, f)

logist_regres_class = SklearnClassifier(LogisticRegression())
logist_regres_class.train(train_set)
print("logistic regression accuracy: ", nltk.classify.accuracy(logist_regres_class, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/logist_regres_class.pickle", "wb") as f:
    pickle.dump(logist_regres_class, f)

SVC = SklearnClassifier(SVC())
SVC.train(train_set)
print("SVC accuracy: ", nltk.classify.accuracy(SVC, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/SVC.pickle", "wb") as f:
    pickle.dump(SVC, f)

nuSVC = SklearnClassifier(NuSVC())
nuSVC.train(train_set)
print("nuSVC accuracy: ", nltk.classify.accuracy(nuSVC, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/nuSVC.pickle", "wb") as f:
    pickle.dump(nuSVC, f)

linearSVC = SklearnClassifier(LinearSVC())
linearSVC.train(train_set)
print("linear SVC accuracy: ", nltk.classify.accuracy(linearSVC, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/linearSVC.pickle", "wb") as f:
    pickle.dump(linearSVC, f)

groupVoting = ClassifiersVoting(nbcClassifier,
                                #multinomialNB_class,
                                #bernulli_class,
                                SGD_class,
                                logist_regres_class,
                                #SVC,
                                nuSVC,
                                linearSVC)

print("voting classifier accuracy: ", nltk.classify.accuracy(groupVoting, testing_set))





print("Lia said:")

text = "In bas, I liked it so much, would see it again"
print(text)
print("This review is:")
print(groupVoting.classify(find_pop(text)))
print("Lia said:")

text = "Mean girls is a shitty movie, and would never see it again, waste of time"
print(text)
print("This review is:")
print(groupVoting.classify(find_pop(text)))

