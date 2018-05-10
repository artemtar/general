import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
style.use("fivethirtyeight")


# First set up the figure, the axis, and the plot element we want to animate
fig=plt.figure()

def animate(i):
    f = open("EmotionData/twitter.txt", "r").read()
    lines = f.split("\n")
    # happiness (hp), sadness (sd), fear (fr), surprise (sp), disgust (dg),
    # anger (ag), and neutral (ne)
    emotions =["hp",
    "sd",
    "fr",
    "sp",
    "dg",
    "ag",
    "ne"]
    emo_dic = {}
    for em in emotions:
        emo_dic[em] = 0
    try:
        for res in lines[-50:]:
            if res in emotions:
                temp = emo_dic[res]
                emo_dic[res] = temp + 1
    except:
        pass

    p1 = plt.barh(emotions, list(emo_dic.values()) ,color='b')
    p1[1].set_color("yellow")
    p1[2].set_color("r")
    p1[3].set_color("grey")
    p1[4].set_color("purple")
    p1[5].set_color("brown")
    p1[6].set_color("green")

    return p1

# call the animator.  blit=True means only re-draw the parts that have changed.
anim = animation.FuncAnimation(fig, animate,frames=200, interval=500, blit=True )
plt.ylabel("emotions")
plt.title("Emotion Analyzer")
plt.show()