# Metadynminer

Metadynminer is R packages for reading, analysis and visualisation of metadynamics HILLS and COLVAR files produced by Plumed.

```R
install.packages("metadynminer") # in future will be added to R repository
library(metadynminer) # in future will be added to R repository

# Reading hills file
hills<-read.hills("HILLS", per=c(TRUE, TRUE)) # done

# Summary
summary(hills) # done

# Plot hills file
plot(hills) # done

# Plot hill heights
plotheights(hills) # done

# Calculate FES by bias sum (fes1d for 1d FES)
fes<-fes2d(hills, tmin=5000, tmax=10000) # done, to do manual

# Calculate FES conventionally (slow, fes1d2 for 1d FES)
fes<-fes2d2(hills, tmin=5000, tmax=10000) # done, to do manual

# You can sum two FESes
fes<-fes1+fes2 # done, to do manual

# You can calculate and substract min, max or mean from a FES
fes<-fes1+min(fes1) # done, to do manual

# In order to make a movie you can use summation of FESes
tfes<-fes2d(hillsf, tmax=1000)
png("test%03d.png")
plot(tfes, zlim=c(-120,0))
for(i in 1:10) {
  tfes<-tfes+fes2d(hillsf, tmin=1000*i, tmax=1000*(i+1)-1)
  plot(tfes, zlim=c(-120,0))
}
dev.off()

# Evaluate FES
summary(fes) # done, to do manual

# Plot FES
plot(fes) # done

# Find minima (fesminima1d for 1d FES)
minima<-fesminima2d(fes) # done, to do manual

# Evaluate free energy minima
summary(minima) # done, to do manual

minima<-emptyminima()

# Plot free energy minima
plot(minima) # 2D done, 1D to do, to do manual

# Calculate free energy profile for a point in CV space (fe1d for 1D FES)
prof<-feprofiles(hills, minima) # done, to do manual

# Find transition path
# Summary of transition path


