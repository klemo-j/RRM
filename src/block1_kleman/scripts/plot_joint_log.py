import numpy as np
import matplotlib.pyplot as plt
import os

file_name = os.path.expanduser("~/joint_log.csv")
data = np.loadtxt(file_name, delimiter=",", skiprows=1)

t   = data[:, 0]
pos = data[:, 1]
vel = data[:, 2]
acc = data[:, 3]

fig, ax = plt.subplots(3, 1, figsize=(14, 9), sharex=True)
fig.suptitle("Klb 3 - poloha, rychlost, zrychlenie pocas celej sekvencie")

ax[0].plot(t, pos, color="steelblue", linewidth=1.8)
ax[0].set_ylabel("poloha [rad]")
ax[0].set_title("Poloha")
ax[0].grid(True)

ax[1].plot(t, vel, color="steelblue", linewidth=1.8)
ax[1].axhline(0, color="black", linewidth=0.7, linestyle="--")
ax[1].set_ylabel("rychlost [rad/s]")
ax[1].set_title("Rychlost - spojita, zacina a konci nulou pri kazdom pohybe")
ax[1].grid(True)

ax[2].plot(t, acc, color="crimson", linewidth=1.8)
ax[2].axhline(0, color="black", linewidth=0.7, linestyle="--")
ax[2].set_ylabel("zrychlenie [rad/s^2]")
ax[2].set_xlabel("cas [s]")
ax[2].set_title("Zrychlenie - spojite, zacina a konci nulou pri kazdom pohybe")
ax[2].grid(True)

plt.tight_layout()
out = os.path.expanduser("~/joint3_analysis.png")
plt.savefig(out, dpi=150)
print(f"Saved: {out}")
plt.show()