# Metadynminer

Metadynminer is R packages for reading, analysis and visualisation of metadynamics HILLS files produced by Plumed.

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
fes<-fes2d(hills, tmin=5000, tmax=10000) # done

# Calculate FES conventionally (slow, fes1d2 for 1d FES)
fes<-fes2d2(hills, tmin=5000, tmax=10000) # done

# You can sum two FESes
fes<-fes1+fes2 # done

# Evaluate FES
summary(fes) # done, to do manual

# Plot FES
plot(fes) # done

# Find minima
minima<-fesminima(fes) # done, to do manual

# Evaluate free energy minima
summary(minima) # done, to do manual

# Plot free energy minima
plot(minima) # 2D done, 1D to do, to do manual

# Calculate free energy
fe<-freeene(cvs, hills, per=c(TRUE, TRUE), time=10000) # to do by linking with Fortran code

# Calculate free energy profile
fe<-freeene2(cvs, hills, per=c(TRUE, TRUE), time=0:10000) # to do by linking with Fortran code

# Calculate free energy difference profile
fe1<-freeene2(cvs1, hills, per=c(TRUE, TRUE), time=0:10000)
fe2<-freeene2(cvs2, hills, per=c(TRUE, TRUE), time=0:10000)
fediff<-fe2-fe1

# Find transition path
# Summary of transition path


