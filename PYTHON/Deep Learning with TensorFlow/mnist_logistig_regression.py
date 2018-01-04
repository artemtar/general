import os

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

import numpy as np
import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
import time

# Define paramaters for the model
learning_rate = 0.001
batch_size = 128
n_epochs = 15
mnist = input_data.read_data_sets('/tmp/mnist', one_hot=True)
n_batches = int(mnist.train.num_examples / batch_size)

X = tf.placeholder(dtype='float32', shape=[batch_size, 784])
Y = tf.placeholder(shape=[batch_size, 10], dtype='float32')

w = tf.Variable(tf.random_normal(shape=[784, 10], mean=0.001, stddev=0.1, dtype='float32'))
b = tf.Variable(tf.random_normal(shape=[1, 10], mean=0.001, stddev=0.1, dtype='float32'))


logits = tf.add(tf.matmul(X, w), b)

# Step 5: define loss function
# use cross entropy loss of the real labels with the softmax of logits
# use the method:
# tf.nn.softmax_cross_entropy_with_logits(logits, Y)
# then use tf.reduce_mean to get the mean loss of the batch
entropy = tf.nn.softmax_cross_entropy_with_logits(labels=Y, logits=logits)
#reduce_mean is used to get scaler out of entropy
loss = tf.reduce_mean(entropy)
# Step 6: define training op
# using gradient descent to minimize loss
optimizer = tf.train.AdamOptimizer(learning_rate).minimize(loss)
init = tf.global_variables_initializer()
with tf.Session() as sess:
    start_time = time.time()
    sess.run(init)
    for i in range(n_epochs):
        total_loss = 0
        for j in range(n_batches):
            x, y = mnist.train.next_batch(batch_size)
            _, l = sess.run([optimizer, loss], feed_dict={X: x, Y: y})
            total_loss += l
        print('Average loss epoch {0}: {1}'.format(i, total_loss / n_batches))

    print('Total time: {0} seconds'.format(time.time() - start_time))

    print('Optimization Finished!')  # should be around 0.35 after 25 epochs

    # test the model
    preds = tf.nn.softmax(logits)
    correct_preds = tf.equal(tf.argmax(preds, 1), tf.argmax(Y, 1))
    accuracy = tf.reduce_sum(tf.cast(correct_preds, tf.float32))  # need numpy.count_nonzero(boolarr) :(

    n_batches = int(mnist.test.num_examples / batch_size)
    total_correct_preds = 0

    for i in range(n_batches):
        X_batch, Y_batch = mnist.test.next_batch(batch_size)
        accuracy_batch = sess.run([accuracy], feed_dict={X: X_batch, Y: Y_batch})
        total_correct_preds += accuracy_batch[0]

    print('Accuracy {0}'.format(total_correct_preds / mnist.test.num_examples))