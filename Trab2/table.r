library(data.table)
size = c(10,20,40,80,100,200,400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600,819200,1638400,3276800)
algorithm = c("merge","comb","insertion","shell","selection","bubble", "mergeinsert_k4", "mergeinsert_k8", "mergeinsert_k32", "mergeinsert_k64")
tab = c("increasing", "decreasing", "random")
outpath = "Saidas/s_"
type = "_decreasing.txt"

name = c()
time = c()
tot_size = c()
file = paste("Saidas/s_merge",type,sep="")
merge = scan(file)
file = paste("Saidas/s_comb",type,sep="")
comb = scan(file)
file = paste("Saidas/s_insertion",type,sep="")
insertion = scan(file)
file = paste("Saidas/s_shell",type,sep="")
shell = scan(file)
file = paste("Saidas/s_selection",type,sep="")
selection = scan(file)
file = paste("Saidas/s_bubble",type,sep="")
bubble = scan(file)
file = paste("Saidas/s_mergeinsert_k4",type,sep="")
mergeinsert_k4 = scan(file)
file = paste("Saidas/s_mergeinsert_k8",type,sep="")
mergeinsert_k8 = scan(file)
file = paste("Saidas/s_mergeinsert_k32",type,sep="")
mergeinsert_k32 = scan(file)
file = paste("Saidas/s_mergeinsert_k64",type,sep="")
mergeinsert_k64 = scan(file)

mydata = data.table(size,merge,comb,insertion,shell,selection,bubble,mergeinsert_k4,mergeinsert_k8,mergeinsert_k32,mergeinsert_k64)
write.csv(mydata, file="tabela_inverso.csv")
lapply(mylist, write, "test2.txt", append=TRUE)