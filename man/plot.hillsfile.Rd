% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/readingandfes.R
\name{plot.hillsfile}
\alias{plot.hillsfile}
\title{Plot hillsfile object}
\usage{
\method{plot}{hillsfile}(x, ignoretime = FALSE, xlab = NULL,
  ylab = NULL, xlim = NULL, ylim = NULL, main = NULL, sub = NULL,
  pch = 1, col = "black", bg = "red", cex = 1, asp = NULL,
  lwd = 1, axes = TRUE, ...)
}
\arguments{
\item{x}{hillsfile object.}

\item{ignoretime}{time in the first column of the HILLS file will be ignored.}

\item{xlab}{a title for the x axis: see 'title'.}

\item{ylab}{a title for the y axis: see 'title'.}

\item{xlim}{numeric vector of length 2, giving the x coordinates range.}

\item{ylim}{numeric vector of length 2, giving the y coordinates range.}

\item{main}{an overall title for the plot: see 'title'.}

\item{sub}{a sub title for the plot: see 'title'.}

\item{pch}{plotting 'character', i.e., symbol to use. See 'points'.}

\item{col}{color code or name, see 'par'.}

\item{bg}{background (fill) color for the open plot symbols given by
'pch = 21:25'.}

\item{cex}{character (or symbol) expansion: a numerical vector. This
works as a multiple of 'par("cex")'.}

\item{asp}{the y/x aspect ratio, see 'plot.window'.}

\item{lwd}{line width for drawing symbols see 'par'.}

\item{axes}{a logical value indicating whether both axes should be drawn
on the plot.}

\item{...}{further arguments passed to or from other methods.}
}
\description{
`plot.hillsfile` plots hillsfile object. For a hillsfile with one collective variable it plots its evolution.
For a hillsfile with two collective variables it plots CV1 vs. CV2.
}
\examples{
plot(acealanme)
}
