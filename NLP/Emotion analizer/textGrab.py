from nltk import word_tokenize, sent_tokenize
from nltk.corpus import stopwords
from nltk.corpus import wordnet as wn
import nltk
import re
#
wordPool = [] #all words in training data
# create dictionary with all data
with  open("trainingData.data", 'r') as file_data:
    print("file:" + file_data.name + " open")
    for line in file_data:
    #line = file_data.readline()
        try:
            val = re.findall('\'\s(.+)\s\'\,', line)
            key = re.findall('\s\'\,(.+)[\r\n]+', line)
            for w in word_tokenize(val[0]):
                wordPool.append(w)
        except:
            print("some kinda error")

noise = list(stopwords.words("english"))
additional_noise = [',', 'I', 'the', '``', '.', '\'\'']
for w in additional_noise:
    noise.append(w)


wordPool_clean = [w for w in wordPool if not w in noise]
print(len(wordPool_clean))

analize_list = []
for w in wordPool_clean:
    try:
        analize_list.append(nltk.stem.WordNetLemmatizer().lemmatize(w))
    except:
        print("another")

analize_list = nltk.FreqDist(analize_list)
print(analize_list.most_common(20))