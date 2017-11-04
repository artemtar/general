import pickle

text = "whatever just to test"
file = open("test.pickle", "wb")
pickle.dump(text, file)
file.close()

file1 = open("test.pickle", "rb")
text2 = pickle.load(file1)
print(text2)
file1.close()
