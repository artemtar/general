from nltk import WordNetLemmatizer

lem = WordNetLemmatizer()
print(lem.lemmatize("better", "a"))
print(lem.lemmatize("predictions", 'n'))