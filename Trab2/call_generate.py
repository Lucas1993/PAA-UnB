import subprocess
import os

size = [10,20,40,80,100,200,400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600,819200,1638400,3276800]
tab = ["0", "increasing", "decreasing", "random"]

if not os.path.isdir("Entradas/"):
	os.makedirs("Entradas/")

for x in size:
	for y in range(1,4):
		name = "Entradas/ent_" + tab[y] + "_" + str(x) + ".txt"
		subprocess.call(["./generate_strings", str(y), str(x), name])
