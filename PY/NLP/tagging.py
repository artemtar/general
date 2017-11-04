import nltk
from nltk.corpus import state_union
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize, sent_tokenize, PunktSentenceTokenizer
from nltk import pos_tag
sample_text = state_union.raw("2006-GWBush.txt")
#print(sample_text) too long and not really intersting


text = "Ok here's a story: One day at school my gff came to me and he literally " \
       "said to me and pointed to a bird on the ground, \"LOOK, A DISTRACTION! \" And " \
        "I looked behind me and she kicked me. I was like" \
        ", \"Oww! Where did you get that from? \" So she told me to \" \
        \"come here and I found this hilarious joke and I was like, \"She wasn't kidding. ' \
        'Lol.\" So I tried it on my bro. Don't EVER try it on your brother if he is mean to you."
print("Text: ")
print(text)

text_sen = sent_tokenize(text)

'''
tagging part of speech of every sentence in
the text
'''
def process_content (text_sent):
    try:
        for w in text_sent:
            words = word_tokenize(w)
            tagged = pos_tag(words)
            print(tagged)
    except Exception as e:
        print(str(e))
#removing noise


noise = stopwords.words("english")
noise.append("\"\"")
noise.append('mean')

text_sen_noiseless = []
for s in text_sen:
    words = word_tokenize(s)
    for w in words:
        if w not in noise:
            text_sen_noiseless.append(w)

print("tag full text")
process_content(text_sen)
print("tag cleared text")
process_content(text_sen_noiseless)

pm = PunktSentenceTokenizer(sample_text)
bush_said = pm.tokenize(text)

print("check on bush:")
print(bush_said)

print("untrained")
simple = sent_tokenize(text)
print(simple)

