import json
import main_module as module
import pickle
from tweepy import Stream
from tweepy import OAuthHandler
from tweepy.streaming import StreamListener

f = open("/home/superuser/Dropbox/keys/tweeter.pickle", "rb")
#consumer key, consumer secret, access token, access secret.
consumer_key = pickle.load(f)
consumer_secret = pickle.load(f)
access_token = pickle.load(f)
access_secret = pickle.load(f)
f.close()

class Listener(StreamListener):

    def on_data(self, data):
        try:

            all_data = json.loads(data)
            tweet = all_data["text"]
            sentiment_value, confidence = module.analyze(tweet)
            print(tweet, sentiment_value, confidence)


            if confidence >= 0.6:
                output = open("EmotionData/twitter.txt", "a")
                output.write(sentiment_value)
                output.write('\n')
                output.close()

            return True
        except:
            pass

    def on_error(self, status):
        print(status)


auth = OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_secret)
print("module started")
twitterStream = Stream(auth, Listener())
twitterStream.filter(languages=["en"], track = ["trump"] )