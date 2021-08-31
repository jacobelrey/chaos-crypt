import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d

x,y,z = np.loadtxt("ExpectedOutput.csv",delimiter=',',unpack=True)
x1,y1,z1=np.loadtxt("output.csv",delimiter=',',unpack=True)

fig = plt.figure()
ax = plt.axes(projection="3d")

ax.plot3D(x,y,z, color="green", linewidth=0.2)
ax.plot3D(x1,y1,z1, linewidth=0.2)

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
plt.show()


dx = abs(x-x1)
dy = abs(y-y1)
dz = abs(y-y1)

plt.plot(x,x1, label="dx")
plt.plot(y,y1, label="dy")
plt.plot(z,z1, label="dz")
