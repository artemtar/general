from nltk import word_tokenize
from nltk.corpus import stopwords
import nltk
import re
import random
import pickle
#
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
#classifier.show_most_informative_features(10)

# save_classifier = open("classifiers/naivebayers.pickle", "wb")
# pickle._dump(classifier, save_classifier)
# save_classifier.close()
#print(classifier.classify(find_popular("I am going to kill you off")))