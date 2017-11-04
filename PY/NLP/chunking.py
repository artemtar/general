import nltk
from nltk.corpus import state_union
from nltk.tokenize import PunktSentenceTokenizer, sent_tokenize

#train_text = state_union.raw("2005-GWBush.txt")
#sample_text = state_union.raw("2006-GWBush.txt")
#custom_sent_tokenizer = PunktSentenceTokenizer(train_text)
#tokenized = custom_sent_tokenizer.tokenize(sample_text)


text = "Ok here's a story: One day at school my gff came to me and he literally " \
       "said to me and pointed to a bird on the ground, \"LOOK, A DISTRACTION! \" And " \
        "I looked behind me and she kicked me. I was like" \
        ", \"Oww! Where did you get that from? \" So she told me to \" \
        \"come here and I found this hilarious joke and I was like, \"She wasn't kidding. ' \
        'Lol.\" So I tried it on my bro. Don't EVER try it on your brother if he is mean to you."
tokenized = sent_tokenize(text)
chunkGram = r"""Chunk: {<RB.?>*<VB.?>*<NNP>+<NN>?}"""
def process_content():
    try:
        for i in tokenized:
            words = nltk.word_tokenize(i)
            tagged = nltk.pos_tag(words)

            chunkParser = nltk.RegexpParser(chunkGram)
            chunked = chunkParser.parse(tagged)
            print(chunked)
            for subtree in chunked.subtrees(filter=lambda t: t.label() == 'Chunk'):
                print(subtree)

            chunked.draw()

    except Exception as e:
        print(str(e))


process_content()