import nltk
import pickle
from nltk.classify import ClassifierI
from statistics import mode
from nltk.classify.scikitlearn import SklearnClassifier
from sklearn.naive_bayes import MultinomialNB, BernoulliNB
from sklearn.linear_model import LogisticRegression, SGDClassifier
from sklearn.svm import SVC, LinearSVC, NuSVC
from nltk.tokenize import word_tokenize

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

file = open("Data/word_frequency_review.pickle", "rb")
future_set = pickle.load(file)
file.close()

def find_pop(review):
    set_document = set(word_tokenize(review))
    #checking if words in the most frequents words
    ispopular = {}
    for w in set_document:
        ispopular[w] = (w in future_set)
    return ispopular

#prepearing classifier
file = open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/nbcClassifier.pickle", "rb")
nbcClassifier = pickle.load(file)
file.close()

# file = open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/multinomialNB_class.pickle", "rb")
# multinomialNB_class = pickle.load(file)
# file.close()

# file = open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/bernulli_class.pickle", "rb")
# bernulli_class = pickle.load(file)
# file.close()
#
file = open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/SGD_class.pickle", "rb")
SGD_class =  pickle.load(file)
file.close()

file = open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/logist_regres_class.pickle", "rb")
logist_regres_class = pickle.load(file)
file.close()

# file = open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/SVC.pickle", "rb")
# SVC = pickle.load(file)
# file.close()

file = open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/nuSVC.pickle", "rb")
nuSVC = pickle.load(file)
file.close()

file = open ("/home/superuser/Dropbox/git/PYTHON/ML/textClassifiers/linearSVC.pickle", "rb")
linearSVC = pickle.load(file)
file.close()


groupVoting = ClassifiersVoting(nbcClassifier,
                                #multinomialNB_class,
                                #bernulli_class,
                                SGD_class,
                                logist_regres_class,
                                #SVC,
                                nuSVC,
                                linearSVC)


def analyze(text):
    futset = find_pop(text)
    return groupVoting.classify(futset), groupVoting.confidence(futset)

