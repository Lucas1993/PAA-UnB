library(ggplot2) 
size = c(10,20,40,80,100,200,400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600,819200,1638400,3276800)
algorithm = c("mergeinsert_k4", "mergeinsert_k8", "mergeinsert_k32", "mergeinsert_k64")
outpath = "Saidas/s_"

name = c()
time = c()
tot_size = c()

for(i in algorithm){
  file = paste(outpath,i,"_decreasing.txt",sep="")
  aux = scan(file)
  for(j in 1:20){
    time = c(time,aux[j])
    tot_size = c(tot_size,size[j])
    name = c(name, i)
  }
}
mydata = data.frame(time,tot_size,name)
ggplot(mydata, aes(x=tot_size, y=time, group=name)) +
  geom_line(aes(linetype=name, color=name))+
  geom_point(aes(color=name))+
  theme(legend.position="right")+
  labs(x="Tamanho da Entrada",y="Tempo(s)")+
  ggtitle("Desempenho dos mergeinsert com entrada desordenada")

#qplot(tot_size, log(time), data = mydata, colour=name,geom = c("point", "line"), xlim = c(0, 3276800))