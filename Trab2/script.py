import subprocess, os, sys

size = [10,20,40,80,100,200,400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600,819200,1638400,3276800]
algorithm = ["merge","comb","insertion","shell","selection","bubble"]
tab = ["increasing", "decreasing", "random"]

if not os.path.isdir("Saidas/"):
	os.makedirs("Saidas/")

for x in algorithm:
	name = "./Algoritimos/" + x + "_sort"
	for y in tab:
		saida = "Saidas/s_" + x + "_" + y + ".txt"
		fp=open(saida, "w+")
		flag = False
		for z in size:
			if flag:
				print("7200.00", file=fp)
				print (x+","+y+"_"+str(z)+": 7200")
				continue
			media = 0.0
			for w in range(0,10):
				entrada = "Entradas/ent_" + y + "_" + str(z) + ".txt"
				p = subprocess.Popen(["time","-p", name, entrada],stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
				try:
					p.wait(timeout = 7000)
				except subprocess.TimeoutExpired:
					print("7200.00",file=fp)
					print (x+","+y+"_"+str(z)+": 7200")
					p.terminate()
					flag = True;
					break
					
				line = ""
				for aux in iter(p.stdout.readline, b''):
					line = str(aux.rstrip())
					break
				line = line.split()
				tempo = line[1].split("'")
				media = media + float(tempo[0])
			if flag is False:
				media = media/10
				media = round(media,2)
				print(media, file=fp)
				print (x+","+y+"_"+str(z)+": " + str(media))

# ESPECIAL PARA O mergeinsert
k = [4,8,32,64]
name = "./Algoritimos/mergeinsert_sort"
for x in k:
	for y in tab:
		saida = "Saidas/s_mergeinsert_" + "k" + str(x) + "_" + y + ".txt"
		fp=open(saida, "w+")
		flag = False
		for z in size:
			if flag:
				print("7200.00", file=fp)
				continue
			media = 0.0
			for w in range(0,10):
				entrada = "Entradas/ent_" + y + "_" + str(z) + ".txt"
				p = subprocess.Popen(["time","-p", name, entrada, str(x)],stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
				try:
					p.wait(timeout = 7000)
				except subprocess.TimeoutExpired:
					print("7200.00",file=fp)
					p.terminate()
					flag = True;
					break
					
				line = ""
				for aux in iter(p.stdout.readline, b''):
					line = str(aux.rstrip())
					break
				line = line.split()
				tempo = line[1].split("'")
				media = media + float(tempo[0])
			if flag is False:
				media = media/10
				media = round(media,2)
				print (str(x)+","+y+"_"+str(z)+": " + str(media))
				print(media, file=fp)

