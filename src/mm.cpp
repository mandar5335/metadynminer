#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix hills1(NumericVector cv1, NumericVector cv2, double width1, double width2, NumericVector heights, int n, int tmin, int tmax) {
  int cv1i, cv2i;
  int ni, nj;
  double z;
  double v[n][n];
  double g[2*n][2*n];
  NumericMatrix vo(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      z = exp(-double(i)*double(i)/2.0/width1/width1-double(j)*double(j)/2.0/width2/width2);
      g[i][j] = z;
      if(j>0) g[i][2*n-j] = z;
      if(i>0) g[2*n-i][j] = z;
      if((i>0)&&(j>0)) g[2*n-i][2*n-j] = z;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = 0.0;
    }
  }
  for (int icv=tmin; icv<tmax; icv++) {
    cv1i = int(cv1[icv]+0.5);
    cv2i = int(cv2[icv]+0.5);
    for (int i = 0; i < n; i++) {
      ni=i-cv1i;
      if(i<cv1i) ni+=2*n;
      for (int j = 0; j < n; j++) {
        nj=j-cv2i;
        if(j<cv2i) nj+=2*n;
        v[i][j] -= heights[icv]*g[ni][nj];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vo(i,j) = v[i][j];
    }
  }
  return vo;
}

// [[Rcpp::export]]
NumericMatrix hills1p1(NumericVector cv1, NumericVector cv2, double width1, double width2, NumericVector heights, int n, int tmin, int tmax) {
  int cv1i, cv2i;
  int ni, nj;
  double z;
  double v[n][n];
  double g[n][2*n];
  NumericMatrix vo(n, n);
  for (int i = 0; i < n/2; i++) {
    for (int j = 0; j < n; j++) {
      z = exp(-double(i)*double(i)/2.0/width1/width1-double(j)*double(j)/2.0/width2/width2);
      g[i][j] = z;
      if(j>0) g[i][2*n-j] = z;
      if(i>0) g[n-i][j] = z;
      if((i>0)&&(j>0)) g[n-i][2*n-j] = z;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = 0.0;
    }
  }
  for (int icv=tmin; icv<tmax; icv++) {
    cv1i = int(cv1[icv]+0.5);
    cv2i = int(cv2[icv]+0.5);
    for (int i = 0; i < n; i++) {
      ni=i-cv1i;
      if(i<cv1i) ni+=n;
      for (int j = 0; j < n; j++) {
        nj=j-cv2i;
        if(j<cv2i) nj+=2*n;
        v[i][j] -= heights[icv]*g[ni][nj];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vo(i,j) = v[i][j];
    }
  }
  return vo;
}

// [[Rcpp::export]]
NumericMatrix hills1p2(NumericVector cv1, NumericVector cv2, double width1, double width2, NumericVector heights, int n, int tmin, int tmax) {
  int cv1i, cv2i;
  int ni, nj;
  double z;
  double v[n][n];
  double g[2*n][n];
  NumericMatrix vo(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n/2; j++) {
      z = exp(-double(i)*double(i)/2.0/width1/width1-double(j)*double(j)/2.0/width2/width2);
      g[i][j] = z;
      if(j>0) g[i][n-j] = z;
      if(i>0) g[2*n-i][j] = z;
      if((i>0)&&(j>0)) g[2*n-i][n-j] = z;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = 0.0;
    }
  }
  for (int icv=tmin; icv<tmax; icv++) {
    cv1i = int(cv1[icv]+0.5);
    cv2i = int(cv2[icv]+0.5);
    for (int i = 0; i < n; i++) {
      ni=i-cv1i;
      if(i<cv1i) ni+=2*n;
      for (int j = 0; j < n; j++) {
        nj=j-cv2i;
        if(j<cv2i) nj+=n;
        v[i][j] -= heights[icv]*g[ni][nj];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vo(i,j) = v[i][j];
    }
  }
  return vo;
}

// [[Rcpp::export]]
NumericMatrix hills1p12(NumericVector cv1, NumericVector cv2, double width1, double width2, NumericVector heights, int n, int tmin, int tmax) {
  int cv1i, cv2i;
  int ni, nj;
  double z;
  double v[n][n];
  double g[n][n];
  NumericMatrix vo(n, n);
  for (int i = 0; i < n/2; i++) {
    for (int j = 0; j < n/2; j++) {
      z = exp(-double(i)*double(i)/2.0/width1/width1-double(j)*double(j)/2.0/width2/width2);
      g[i][j] = z;
      if(j>0) g[i][n-j] = z;
      if(i>0) g[n-i][j] = z;
      if((i>0)&&(j>0)) g[n-i][n-j] = z;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = 0.0;
    }
  }
  for (int icv=tmin; icv<tmax; icv++) {
    cv1i = int(cv1[icv]+0.5);
    cv2i = int(cv2[icv]+0.5);
    for (int i = 0; i < n; i++) {
      ni=i-cv1i;
      if(i<cv1i) ni+=n;
      for (int j = 0; j < n; j++) {
        nj=j-cv2i;
        if(j<cv2i) nj+=n;
        v[i][j] -= heights[icv]*g[ni][nj];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vo(i,j) = v[i][j];
    }
  }
  return vo;
}

// [[Rcpp::export]]
NumericMatrix hills2(NumericVector cv1, NumericVector cv2, NumericVector width1, NumericVector width2, NumericVector heights, int n, int tmin, int tmax) {
  double dcv1;
  double dcv2;
  double v[n][n];
  NumericMatrix vo(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j]=0.0;
    }
  }
  for (int icv=tmin = 0; icv < tmax; icv++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dcv1 = cv1[icv]-double(i);
        dcv2 = cv2[icv]-double(j);
        v[i][j] -= heights[icv]*exp(-dcv1*dcv1/2.0/width1[icv]/width1[icv]-dcv2*dcv2/2.0/width2[icv]/width2[icv]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vo(i, j) = v[i][j];
    }
  }
  return vo;
}

// [[Rcpp::export]]
NumericMatrix hills2p1(NumericVector cv1, NumericVector cv2, NumericVector width1, NumericVector width2, NumericVector heights, int n, int tmin, int tmax) {
  double dcv1;
  double dcv2;
  double v[n][n];
  NumericMatrix vo(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j]=0.0;
    }
  }
  for (int icv=tmin = 0; icv < tmax; icv++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dcv1 = cv1[icv]-double(i);
        dcv2 = cv2[icv]-double(j);
        if(dcv1 >  double(n)/2.0) dcv1 -= double(n);
        if(dcv1 < -double(n)/2.0) dcv1 += double(n);
        v[i][j] -= heights[icv]*exp(-dcv1*dcv1/2.0/width1[icv]/width1[icv]-dcv2*dcv2/2.0/width2[icv]/width2[icv]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vo(i, j) = v[i][j];
    }
  }
  return vo;
}


// [[Rcpp::export]]
NumericMatrix hills2p2(NumericVector cv1, NumericVector cv2, NumericVector width1, NumericVector width2, NumericVector heights, int n, int tmin, int tmax) {
  double dcv1;
  double dcv2;
  double v[n][n];
  NumericMatrix vo(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j]=0.0;
    }
  }
  for (int icv=tmin = 0; icv < tmax; icv++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dcv1 = cv1[icv]-double(i);
        dcv2 = cv2[icv]-double(j);
        if(dcv2 >  double(n)/2.0) dcv2 -= double(n);
        if(dcv2 < -double(n)/2.0) dcv2 += double(n);
        v[i][j] -= heights[icv]*exp(-dcv1*dcv1/2.0/width1[icv]/width1[icv]-dcv2*dcv2/2.0/width2[icv]/width2[icv]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vo(i, j) = v[i][j];
    }
  }
  return vo;
}

// [[Rcpp::export]]
NumericMatrix hills2p12(NumericVector cv1, NumericVector cv2, NumericVector width1, NumericVector width2, NumericVector heights, int n, int tmin, int tmax) {
  double dcv1;
  double dcv2;
  double v[n][n];
  NumericMatrix vo(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j]=0.0;
    }
  }
  for (int icv=tmin = 0; icv < tmax; icv++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dcv1 = cv1[icv]-double(i);
        dcv2 = cv2[icv]-double(j);
        if(dcv1 >  double(n)/2.0) dcv1 -= double(n);
        if(dcv1 < -double(n)/2.0) dcv1 += double(n);
        if(dcv2 >  double(n)/2.0) dcv2 -= double(n);
        if(dcv2 < -double(n)/2.0) dcv2 += double(n);
        v[i][j] -= heights[icv]*exp(-dcv1*dcv1/2.0/width1[icv]/width1[icv]-dcv2*dcv2/2.0/width2[icv]/width2[icv]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vo(i, j) = v[i][j];
    }
  }
  return vo;
}

// [[Rcpp::export]]
NumericVector hills1d1(NumericVector cv1, double width1, NumericVector heights, int n, int tmin, int tmax) {
  int cv1i;
  int ni;
  double z;
  double v[n];
  double g[2*n];
  NumericVector vo(n);
  for (int i = 0; i < n; i++) {
    z = exp(-double(i)*double(i)/2.0/width1/width1);
    g[i] = z;
    if(i>0) g[2*n-i] = z;
  }
  for (int i = 0; i < n; i++) {
    v[i] = 0.0;
  }
  for (int icv=tmin; icv<tmax; icv++) {
    cv1i = int(cv1[icv]+0.5);
    for (int i = 0; i < n; i++) {
      ni=i-cv1i;
      if(i<cv1i) ni+=2*n;
      v[i] -= heights[icv]*g[ni];
    }
  }
  for (int i = 0; i < n; i++) {
    vo(i) = v[i];
  }
  return vo;
}

// [[Rcpp::export]]
NumericVector hills1d1p(NumericVector cv1, double width1, NumericVector heights, int n, int tmin, int tmax) {
  int cv1i;
  int ni;
  double z;
  double v[n];
  double g[n];
  NumericVector vo(n);
  for (int i = 0; i < n/2; i++) {
    z = exp(-double(i)*double(i)/2.0/width1/width1);
    g[i] = z;
    if(i>0) g[n-i] = z;
  }
  for (int i = 0; i < n; i++) {
    v[i] = 0.0;
  }
  for (int icv=tmin; icv<tmax; icv++) {
    cv1i = int(cv1[icv]+0.5);
    for (int i = 0; i < n; i++) {
      ni=i-cv1i;
      if(i<cv1i) ni+=n;
      v[i] -= heights[icv]*g[ni];
    }
  }
  for (int i = 0; i < n; i++) {
    vo(i) = v[i];
  }
  return vo;
}

