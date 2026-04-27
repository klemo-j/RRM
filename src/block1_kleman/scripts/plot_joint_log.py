
import numpy as np
import matplotlib.pyplot as plt


file_name = "/home/kllemo/ros2_ws/joint3_log.csv"

data = np.loadtxt(file_name, delimiter=",", skiprows=1)

time = data[:, 0]
position = data[:, 1]
velocity = data[:, 2]
acceleration = data[:, 3]

plt.figure()
plt.plot(time, position)
plt.grid(True)
plt.xlabel("čas [s]")
plt.ylabel("poloha q3 [rad]")
plt.title("Poloha kĺbu 3")

plt.figure()
plt.plot(time, velocity)
plt.grid(True)
plt.xlabel("čas [s]")
plt.ylabel("rýchlosť dq3 [rad/s]")
plt.title("Rýchlosť kĺbu 3")

plt.figure()
plt.plot(time, acceleration)
plt.grid(True)
plt.xlabel("čas [s]")
plt.ylabel("zrýchlenie ddq3 [rad/s²]")
plt.title("Zrýchlenie kĺbu 3")

plt.show()