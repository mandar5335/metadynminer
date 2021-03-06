% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/nebs.R
\name{pointsonfes}
\alias{pointsonfes}
\title{Plot points for Nudged Elastic Band projected onto free energy surface}
\usage{
pointsonfes(x, pch = NULL, cex = 1, bg = NULL, col = "red",
  lwd = 1)
}
\arguments{
\item{x}{nebpath object.}

\item{pch}{plotting 'character', i.e., symbol to use. See 'points'.}

\item{cex}{character (or symbol) expansion: a numerical vector. This
works as a multiple of 'par("cex")'.}

\item{bg}{background (fill) color for the open plot symbols given by
'pch = 21:25'.}

\item{col}{color code or name, see 'par'.}

\item{lwd}{line width for drawing symbols see 'par'.}
}
\description{
`pointsonfes` plots points for free energy profile calculated by Nudged Elastic Band
projected onto free energy surface.
}
\examples{
tfes<-fes(acealanme, imax=5000)
minima<-fesminima(tfes)
nebAD<-neb(minima, min1="A", min2="D", nsteps=20)
plot(minima)
pointsonfes(nebAD)
}
