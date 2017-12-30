

import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets("/tmp/data/", one_hot = True)


# design values of network




n_nodes_l1 = 500
n_nodes_l2 = 500
n_nodes_l3 = 500

n_classes = 10
batch_size = 100

x = tf.placeholder('float', [None, 784])
y = tf.placeholder('float')


# model



def deepWeb(data):
    layer1 = {'weights': tf.Variable(tf.random_normal([784, n_nodes_l1])),
              'biases': tf.Variable(tf.random_normal([n_nodes_l1]))}
    layer2 = {'weights': tf.Variable(tf.random_normal([n_nodes_l1, n_nodes_l2])),
              'biases': tf.Variable(tf.random_normal([n_nodes_l2]))}
    layer3 = {'weights': tf.Variable(tf.random_normal([n_nodes_l2, n_nodes_l3])),
              'biases': tf.Variable(tf.random_normal([n_nodes_l3]))}


    layerOut = {'weights': tf.Variable(tf.random_normal([n_nodes_l3, n_classes])),
            'biases': tf.Variable(tf.random_normal([n_classes]))}


    #activation function
    l1 = tf.add(tf.matmul(data, layer1['weights']), layer1['biases'])
    l1 = tf.nn.relu(l1)
    l2 = tf.add(tf.matmul(l1, layer2['weights']), layer2['biases'])
    l2 = tf.nn.relu(l2)
    l3 = tf.add(tf.matmul(l2, layer3['weights']), layer3['biases'])
    l3 = tf.nn.relu(l3)

    outl = tf.add(tf.matmul(l3, layerOut['weights']), layerOut['biases'])



    return outl



def train(input):
    prediction = deepWeb(input)
    #how label is decided?
    cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=prediction, labels=y))
    optimizer = tf.train.AdamOptimizer().minimize(cost)

    n_epochs = 10
    with tf.Session() as sess:
        sess.run(tf.global_variables_initializer())
        
        for epoch in range(n_epochs):
            epoch_cost = 0
            for _ in range (int(mnist.train.num_examples/batch_size)):
                #check whar is tranin next
                epoch_data, epoch_lable = mnist.train.next_batch(batch_size)
                #how come to current situation
                _, c = sess.run([optimizer, cost], feed_dict={x: epoch_data, y: epoch_lable})
                epoch_cost += c

            print('Epoch', epoch + 1, 'out of', n_epochs, 'cost', epoch_cost)

            correct = tf.equal(tf.argmax(prediction, 1), tf.argmax(y, 1))
            accuracy = tf.reduce_mean(tf.cast(correct, "float"))
            print("Accuracy ", accuracy.eval({x: mnist.test.images, y: mnist.test.labels}))




train(x)
