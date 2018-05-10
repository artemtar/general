import nltk
import pickle
from nltk.classify import ClassifierI
from nltk.tokenize import word_tokenize
from nltk.classify.scikitlearn import SklearnClassifier
from sklearn.naive_bayes import MultinomialNB, BernoulliNB
from sklearn.linear_model import LogisticRegression, SGDClassifier
from sklearn.svm import SVC, LinearSVC, NuSVC
from nltk.tokenize import word_tokenize

#conglameration of classifiers; group voting; loose implementation of adaboost
class ClassifiersVoting(ClassifierI):
    def __init__(self, *classifiers):
        self._classifiers = classifiers
    # happiness (hp), sadness (sd), fear (fr), surprise (sp), disgust (dg),
    # anger (ag), and neutral (ne)
    def classify(self, featureset):

        emo_dic = {}

        i = 0.05 #vote modifier
        for clas in self._classifiers:
            vote = clas.classify(featureset)
            if vote not in emo_dic.keys():
                emo_dic[vote] = 1 + i
            else:
                emo_dic[vote] += 1 + i
            i += 0.05
    # checking for the vote with highest result
        highest = 0
        classification = ''
        for key in emo_dic:
            if emo_dic[key] > highest:
                classification = key
                highest = emo_dic[key]
        return classification

    def confidence(self, featureset):

            classification = self.classify(featureset)
            count = 0
            if classification == "ne":
                count = -2
            votes = []
            for c in self._classifiers:
                vote = c.classify(featureset)
                votes.append(vote)
                if vote == classification:
                    count += 1
            return count / len(self._classifiers)#, votes

file = open("EmotionData/word_frequency_reveiw.pickle", "rb")
frequency_list = pickle.load(file)
file.close()
print(len(frequency_list))
future_set = frequency_list


# file = open("EmotionData/test.pickle", "rb")
# test_data = pickle.load(file)
# file.close()
# print(len(test_data))
# for w in test_data:
#     print(w)

# print(test_data[0])
# print(len(test_data))
def find_popular(d):
    popular = {}
    set_of_words = set(word_tokenize(d))
    for w in set_of_words:
        w = w.lower()
        try:
            w = (nltk.stem.WordNetLemmatizer().lemmatize(w))
        except:
            print("warning")
        popular[w] = (w in future_set)
    return popular

# prepearing classifier
# file = open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/nbcClassifier.pickle", "rb")
# nbcClassifier = pickle.load(file)
# file.close()

file = open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/multinomialNB_class.pickle", "rb")
multinomialNB_class = pickle.load(file)
file.close()

file = open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/bernulli_class.pickle", "rb")
bernulli_class = pickle.load(file)
file.close()

file = open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/SGD_class.pickle", "rb")
SGD_class =  pickle.load(file)
file.close()

file = open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/logist_regres_class.pickle", "rb")
logist_regres_class = pickle.load(file)
file.close()

# file = open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/SVC.pickle", "rb")
# SVC = pickle.load(file)
# file.close()

# file = open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/nuSVC.pickle", "rb")
# nuSVC = pickle.load(file)
# file.close()

file = open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/linearSVC.pickle", "rb")
linearSVC = pickle.load(file)
file.close()



groupVoting = ClassifiersVoting(#nbcClassifier,
                                bernulli_class,
                                multinomialNB_class,
                                SGD_class,
                                logist_regres_class,
                                #SVC,
                                #nuSVC,
                                linearSVC
                                 )

# print(nltk.classify.accuracy(groupVoting, test_data))

def analyze(text):
    feature_set = find_popular(text)
    return groupVoting.classify(feature_set), groupVoting.confidence(feature_set)

# ph = "My life on the weekdays is tae kwon do its what i was born to do i love i there i love to teach people who want to be taught"
#ph1 = "WATCH: Congressman Warns Of Coup Plan Against Trump On The House Floor!"
# ph2 = "I can t believe she is FINALLY here!!"
#
#
#
#print(find_popular(ph1))
# print(analyze(ph1))
#print("nuSVC accuracy: ",  linearSVC.classify((find_popular(ph))))
# print("nuSVC accuracy: ",  SGD_class.classify(find_popular(ph2)))
# print("nuSVC accuracy: ",  multinomialNB_class.classify(find_popular(ph1)))
#
#print(nltk.classify.accuracy(linearSVC, test_data))
#print(groupVoting.confidence(find_popular(ph1)))