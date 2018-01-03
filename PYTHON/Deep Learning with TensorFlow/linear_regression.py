import os

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
import xlrd

#import utils

DATA_FILE = 'data/fire_theft.xls'

# read in data from the .xls file
book = xlrd.open_workbook(DATA_FILE, encoding_override='utf-8')
sheet = book.sheet_by_index(0)
data = np.asarray([sheet.row_values(i) for i in range(1, sheet.nrows)])
n_samples = sheet.nrows - 1
# create placeholders for input X (number of fire) and label Y (number of theft)
X = tf.placeholder(dtype='float32')
Y = tf.placeholder(dtype='float32')

#  create weight and bias, initialized to 0
w = tf.Variable(initial_value=0.)
b = tf.Variable(initial_value=0.)
# Step 4: predict Y (number of theft) from the number of fire
# name your variable Y_predicted
Y_predicted = w * X + b

# use the square error as the loss function
#loss = tf.squared_difference(Y, Y_predicted, name="loss")

def huber_loss(labels, prediction, delta = 1):
    check = np.abs(labels - prediction)
    cond = tf.less(check, delta)
    return tf.where(cond, 0.5 * (labels - prediction),
                    np.square(labels - prediction));
#  using gradient descent with learning rate of 0.01 to minimize loss
optimizer = tf.train.GradientDescentOptimizer(0.00001).minimize(huber_loss(Y, Y_predicted))
# Train model
init = tf.global_variables_initializer()
with tf.Session() as sess:
    #  initialize the necessary variables, in this case, w and b
    # TO - DO
    sess.run(init)
    for i in range(10):
        total_loss = 0
        for x, y in data:
            # Session runs optimizer to minimize loss and fetch the value of loss. Name the received value as l
            _, l = sess.run([optimizer, huber_loss(Y, Y_predicted)], feed_dict={X: x, Y: y})
            total_loss += l
        print("Epoch {0}: {1}".format(i, total_loss / n_samples))
    w, b = sess.run([w, b])

X, Y = data.T[0], data.T[1]
plt.plot(X, Y, 'bo', label='Real data')
plt.plot(X, X * w + b, 'r', label='Predicted data')
plt.legend()
plt.show()