import numpy as np
import matplotlib.pyplot as plt

datos=np.loadtxt("datos.txt")
x=datos[:,1]
y=datos[:,0]


plt.plot(x,y)
plt.xlabel("p2")
plt.ylabel("q2")
plt.savefig("caos.pdf")

