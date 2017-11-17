from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
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
        res = 0
        classification = ''
        for key in emo_dic:
            if emo_dic[key] > res:
                classification = key

        return classification

    def confidence(self, parameters):


            votes = []
            for clas in self._classifiers:
                vote = clas.classify(parameters)
                votes.append(vote)
            #count confidence
            most = votes.count(mode(votes))
            return most / len(votes)



wordPool = [] #all words in training data
countne = 0
data = [] #all data
# create dictionary with all data
with  open("trainingData.data", 'r') as file_data:
    print("file:" + file_data.name + " open")
    for line in file_data:
        try:
            val = re.findall('\'\s(.+)\s\'\,', line)
            key = re.findall('\s\'\,(.+)[\r\n]+', line)
            # if key[0] != 'ne':
            #     countne += 1
            sent = []
            for w in word_tokenize(val[0]):
                wordPool.append(w)
                sent.append(w)

            data.append((sent, key[0]))
        except:
            print("warning")
print(countne, "this is negative")
random.shuffle(data)
#remove noisy data from analize list
noise = list(stopwords.words("english"))
additional_noise = [',', 'I', 'the', '``', '.', '\'\'', 'The', '(', ')']
for w in additional_noise:
    if w not in noise:
        noise.append(w)

wordPool_clean = [w for w in wordPool if not w in noise]

print(len(wordPool), "all words")
print(len(wordPool_clean), "cleaned noise set")

# J  = adjective, R = adverb, V = verb
allowed_types = ["J", "R", "V"]
allowed_wordPool_clean = []

tagged = nltk.pos_tag(wordPool_clean)
for w in tagged:
    if w[1][0] in allowed_types:
        allowed_wordPool_clean.append(w[0])

analyze_list = []
for w in allowed_wordPool_clean:
    w = w.lower()
    try:
        analyze_list.append(nltk.stem.WordNetLemmatizer().lemmatize(w))
    except:
        print("warning")


#additional emotion words, going straight into frequency set
emotion_words = []
anger = open("EmotionData/anger.txt", "r")
for line in anger:
    words = re.findall('\d\s(.+)[\r\n]+', line)
    for w in words:
        token = word_tokenize(w)
        for t in token:
            emotion_words.append(t)

disgust = open("EmotionData/disgust.txt", "r")
for line in anger:
    words = re.findall('\d\s(.+)[\r\n]+', line)
    for w in words:
        token = word_tokenize(w)
        for t in token:
            emotion_words.append(t)

fear = open("EmotionData/fear.txt", "r")
for line in anger:
    words = re.findall('\d\s(.+)[\r\n]+', line)
    for w in words:
        token = word_tokenize(w)
        for t in token:
            emotion_words.append(t)

joy = open("EmotionData/joy.txt", "r")
for line in anger:
    words = re.findall('\d\s(.+)[\r\n]+', line)
    for w in words:
        token = word_tokenize(w)
        for t in token:
            emotion_words.append(t)

sadness = open("EmotionData/sadness.txt", "r")
for line in anger:
    words = re.findall('\d\s(.+)[\r\n]+', line)
    for w in words:
        token = word_tokenize(w)
        for t in token:
            emotion_words.append(t)

surprize = open("EmotionData/surprise.txt", "r")
for line in anger:
    words = re.findall('\d\s(.+)[\r\n]+', line)
    for w in words:
        token = word_tokenize(w)
        for t in token:
            emotion_words.append(t)

anger.close()
disgust.close()
fear.close()
joy.close()
sadness.close()
surprize.close()

manually_add = ["!", "?", "!!!", "!?", "wtf", "heck",":)", ":(", ":D"]

print(len(analyze_list), "ready and clean")
frequent_list = nltk.FreqDist(analyze_list)
frequent_list = [w for (w, i) in list(frequent_list.most_common(5000))]


for w in manually_add:
    if w not in analyze_list:
        w = w.lower()
        frequent_list.append(w)
for w in emotion_words:
    if w not in analyze_list:
        w = w.lower()
        frequent_list.append(w)

print(frequent_list[:20])
print(len(frequent_list))

with open("EmotionData/word_frequency_reveiw.pickle", "wb") as wfr:
    pickle.dump(frequent_list, wfr)

def find_popular (d):
    popular = {}
    set_of_words = set(d)
    for w in set_of_words:
        try:
            w = w.lower()
            w = (nltk.stem.WordNetLemmatizer().lemmatize(w))
        except:
            print("warning")
        popular[w] = (w in frequent_list)
    return popular

#check frequency for full data set
revised_data = ((find_popular(comment), category) for (comment, category) in data)
revised_data_list = list(revised_data)
print(len(revised_data_list), "full set")
test_data = revised_data_list[2500:]
training_data = revised_data_list[:2500]

with open("EmotionData/test.pickle", "wb") as wfr:
    pickle.dump(test_data, wfr)

print(find_popular(["it is good weather today he bad"]), "check")

#prepearing classifier
nbcClassifier = nltk.NaiveBayesClassifier.train(training_data)
nbcClassifier.train(test_data)
print("nlk naive accuracy: ", nltk.classify.accuracy(nbcClassifier, test_data))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/nbcClassifier.pickle", "wb") as f:
    pickle.dump(nbcClassifier, f)

#off at 2000 res 65%
multinomialNB_class = SklearnClassifier(MultinomialNB())
multinomialNB_class.train(training_data)
print("multibinomial accuracy: ", nltk.classify.accuracy(multinomialNB_class, test_data))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/multinomialNB_class.pickle", "wb") as f:
    pickle.dump(multinomialNB_class, f)

#60%
bernulli_class = SklearnClassifier(BernoulliNB())
bernulli_class.train(training_data)
print("bersnulli accuracy: ", nltk.classify.accuracy(bernulli_class, test_data))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/bernulli_class.pickle", "wb") as f:
    pickle.dump(bernulli_class, f)

#switched at 5000 res 68%
SGD_class= SklearnClassifier(SGDClassifier())
SGD_class.train(training_data)
print("SGD accuracy: ", nltk.classify.accuracy(SGD_class, test_data))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/SGD_class.pickle", "wb") as f:
    pickle.dump(SGD_class, f)

#switched as 3000 result 71%
logist_regres_class = SklearnClassifier(LogisticRegression())
logist_regres_class.train(training_data)
print("logistic regression accuracy: ", nltk.classify.accuracy(logist_regres_class, test_data))

with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/logist_regres_class.pickle", "wb") as f:
    pickle.dump(logist_regres_class, f)

#switched off at 4000 frequency list
# SVC = SklearnClassifier(SVC())
# SVC.train(training_data)
# print("SVC accuracy: ", nltk.classify.accuracy(SVC, test_data))
#
# with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/SVC.pickle", "wb") as f:
#     pickle.dump(SVC, f)
#
# nuSVC = SklearnClassifier(NuSVC())
# nuSVC.train(training_data)
# print("nuSVC accuracy: ", nltk.classify.accuracy(nuSVC, test_data))
#
# with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/nuSVC.pickle", "wb") as f:
#     pickle.dump(nuSVC, f)

#switch of at 4000 frequency res 77%
# linearSVC = SklearnClassifier(LinearSVC())
# linearSVC.train(training_data)
# print("linearSVC accuracy: ", nltk.classify.accuracy(linearSVC, test_data))
#
# with open ("/home/superuser/Dropbox/git/PYTHON/ML/EmotionAnalyzer/linearSVC.pickle", "wb") as f:
#     pickle.dump(linearSVC, f)

groupVoting = ClassifiersVoting(nbcClassifier,
                                #multinomialNB_class,
                                #bernulli_class,
                                #SGD_class,
                                #logist_regres_class,
                                #SVC,
                                #nuSVC,
                                #linearSVC
                                )

print(nbcClassifier.classify(find_popular("Hello, whatever, bad pucka")))
print(bernulli_class.classify(find_popular("Hello, whatever, bad pucka")))
print(groupVoting.classify(find_popular("Hello, whatever, bad pucka")))


