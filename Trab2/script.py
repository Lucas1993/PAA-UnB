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
				continue
			media = 0.0
			for w in range(0,3):
				entrada = "Entradas/ent_" + y + "_" + str(z) + ".txt"
				p = subprocess.Popen(["time","-p", name, entrada],stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
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
				#print (x+","+y+"_"+str(z)+": " + tempo[0])
				media = media + float(tempo[0])
			if flag is False:
				media = media/3
				media = round(media,2)
				print(media, file=fp)

# ESPECIAL PARA O merge_insert
k = [4,8,32,64]
name = "./Algoritimos/merge_insert_sort"
for x in k:
	for y in tab:
		saida = "Saidas/s_merge_insert_" + "k" + str(x) + "_" + y + ".txt"
		fp=open(saida, "w+")
		flag = False
		for z in size:
			if flag:
				print("7200.00", file=fp)
				continue
			media = 0.0
			for w in range(0,3):
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
				#print (x+","+y+"_"+str(z)+": " + tempo[0])
				media = media + float(tempo[0])
			if flag is False:
				media = media/3
				media = round(media,2)
				print(media, file=fp)

