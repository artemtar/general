import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import time
import numpy as np
style.use("fivethirtyeight")
#
import mpl_toolkits.mplot3d.axes3d as p3

import random

# First set up the figure, the axis, and the plot element we want to animate
fig=plt.figure()

def animate(i):
    f = open("twitter.txt", "r").read()
    lines = f.split("\n")
    print(lines)
    pos = 0
    neg = 0
    for res in lines[-200:]:
        if res == "pos":
            pos += 1
        else:
            neg += 1
    p1 = plt.barh(["ne", "pos"],[neg, pos] ,color='b')
    p1[0].set_color("y")
    return p1

# call the animator.  blit=True means only re-draw the parts that have changed.
anim = animation.FuncAnimation(fig, animate,frames=200, interval=1000 )
plt.ylabel("pos")
plt.title("whatever")
plt.show()