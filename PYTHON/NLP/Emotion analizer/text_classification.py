from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize, sent_tokenize
import random
import nltk
import pickle
import re
from nltk.classify import ClassifierI
from statistics import mode
from nltk.classify.scikitlearn import SklearnClassifier
from sklearn.naive_bayes import MultinomialNB, BernoulliNB
from sklearn.linear_model import LogisticRegression, SGDClassifier
from sklearn.svm import SVC, LinearSVC, NuSVC

#conglameration of classifiers; group voting; loose implementation of adaboost
class ClassifiersVoting(ClassifierI):
    def __init__(self, *classifiers, **kwargs):
        self._classifiers = classifiers
    #decision making
    def classify(self, featureset):
        votes = []
        for classifier in self._classifiers:
            votes.append(classifier.classify(find_popular(featureset)))
        return mode(votes)
    #confidence level.
    def confidence (self, featureset):
        votes = []
        for c in self._classifiers:
            votes.append(c.classify(find_popular(featureset)))
        return mode(votes)/len(votes)



wordPool = [] #all words in training data

data = [] #all data
# create dictionary with all data
with  open("trainingData.data", 'r') as file_data:
    print("file:" + file_data.name + " open")
    for line in file_data:
    #line = file_data.readline()
        try:
            val = re.findall('\'\s(.+)\s\'\,', line)
            key = re.findall('\s\'\,(.+)[\r\n]+', line)
            sent = []
            for w in word_tokenize(val[0]):
                wordPool.append(w)
                sent.append(w)
            #if key[0] != 'ne':
            data.append((sent, key[0]))
        except:
            print("some kinda error")
random.shuffle(data)
#remove noisy data from analize list
noise = list(stopwords.words("english"))
additional_noise = [',', 'I', 'the', '``', '.', '\'\'']
for w in additional_noise:
    if w not in noise:
        noise.append(w)

wordPool_clean = [w for w in wordPool if not w in noise]

print(len(wordPool))
analize_list = []
for w in wordPool_clean:
    try:
        analize_list.append(nltk.stem.WordNetLemmatizer().lemmatize(w))
    except:
        print("another")

frequent_list = list(nltk.FreqDist(analize_list))[:2000]

def find_popular (d):
    popular = {}
    set_of_words = set(d)
    for w in set_of_words:
        popular[w] = (w in frequent_list)
    return popular
#check frequency for full data set
revised_data = ((find_popular(comment), category) for (comment, category) in data)
revised_data_list = list(revised_data)
print(len(revised_data_list))
test_data = revised_data_list[1950:]
training_data = revised_data_list[:1950]

#naive classifier
# classifier = nltk.NaiveBayesClassifier.train(training_data)
classifier_file = open("classifiers/naivebayers.pickle", "rb")
classifier = pickle.load(classifier_file)
classifier_file.close()
print("NaiveBayersClassifier accuracy:")
print(nltk.classify.accuracy(classifier, test_data) * 100)


#prepearing classifier
nbcClassifier = nltk.NaiveBayesClassifier.train(train_set)
nbcClassifier.train(train_set)
print("nlk naive accuracy: ", nltk.classify.accuracy(nbcClassifier, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/nbcClassifier.pickle", "wb") as f:
    pickle.dump(nbcClassifier, f)


multinomialNB_class = SklearnClassifier(MultinomialNB())
multinomialNB_class.train(train_set)
print("multibinomial accuracy: ", nltk.classify.accuracy(multinomialNB_class, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/multinomialNB_class.pickle", "wb") as f:
    pickle.dump(multinomialNB_class, f)

bernulli_class = SklearnClassifier(BernoulliNB())
bernulli_class.train(train_set)
print("bersnulli accuracy: ", nltk.classify.accuracy(bernulli_class, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/bernulli_class.pickle", "wb") as f:
    pickle.dump(bernulli_class, f)

SGD_class= SklearnClassifier(SGDClassifier())
SGD_class.train(train_set)
print("SGD accuracy: ", nltk.classify.accuracy(SGD_class, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/SGD_class.pickle", "wb") as f:
    pickle.dump(SGD_class, f)

logist_regres_class = SklearnClassifier(LogisticRegression())
logist_regres_class.train(train_set)
print("logistic regression accuracy: ", nltk.classify.accuracy(logist_regres_class, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/logist_regres_class.pickle", "wb") as f:
    pickle.dump(logist_regres_class, f)

SVC = SklearnClassifier(SVC())
SVC.train(train_set)
print("SVC accuracy: ", nltk.classify.accuracy(SVC, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/SVC.pickle", "wb") as f:
    pickle.dump(SVC, f)

nuSVC = SklearnClassifier(NuSVC())
nuSVC.train(train_set)
print("nuSVC accuracy: ", nltk.classify.accuracy(nuSVC, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/nuSVC.pickle", "wb") as f:
    pickle.dump(nuSVC, f)

linearSVC = SklearnClassifier(LinearSVC())
linearSVC.train(train_set)
print("linear SVC accuracy: ", nltk.classify.accuracy(linearSVC, testing_set))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/linearSVC.pickle", "wb") as f:
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