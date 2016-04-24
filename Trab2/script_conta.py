import subprocess, os, sys

size = [10,20,40,80,100,200,400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600,819200,1638400,3276800]
tab = ["increasing", "decreasing", "random"]

if not os.path.isdir("Saidas/"):
	os.makedirs("Saidas/")

for y in tab:
	saida = "Saidas/conta_inversoes_" + y + ".txt"
	fp=open(saida, "w+")
	for z in size:
		entrada = "Entradas/ent_" + y + "_" + str(z) + ".txt"
		p = subprocess.Popen(["./conta_inversoes",entrada],stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
		line = ""
		for aux in iter(p.stdout.readline, b''):
			line = str(aux.rstrip())
			break
		aux = line.split("'")
		print(aux[1], file=fp)