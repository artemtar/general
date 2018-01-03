import tensorflow as tf
#
# x = tf.constant([3,4])
# y = tf.constant(2)
# f = tf.add(x,y, name="coolAdd")

# with tf.Session() as sess:
#     out = sess.run(f)
#     writer = tf.summary.FileWriter('./graphs', sess.graph)

w = tf.Variable(1.0, name="weight")

w = tf.Variable(1.0, name="weight")
with tf.Session() as sess:
    sess.run(w.initializer)
    print(sess.run(w)) 