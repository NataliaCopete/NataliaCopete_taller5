import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation



datos=np.loadtxt("datos.txt")
x=np.linspace(0,100,125)


fig,ax=plt.subplots()

cuerda,=ax.plot(x,datos[0:125])
c=plt.gca()
c.set_ylim([-1.0,1.0])

def update(i):
  cuerda.set_ydata(datos[i*125:(i+1)*125])
  return cuerda

marcos=np.arange(0,250)
anim=FuncAnimation(fig,update,frames=marcos,interval=20)

anim.save("cuerda.gif",dpi=60,writer='imagemagick')
