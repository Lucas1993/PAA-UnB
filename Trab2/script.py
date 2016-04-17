import subprocess

rc = subprocess.run("timeout 1s time ./Algoritimos/merge_sort < Entradas/ent_decreasing_819200.txt", shell=True, stdout=subprocess.PIPE)
print (rc)