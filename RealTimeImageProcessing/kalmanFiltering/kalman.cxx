#include <iostream>
//#include <stdexcept>

#include "kalman.h"

KalmanFilter::KalmanFilter(
    double dt,
    const Eigen::MatrixXd& A, // syatem dynamics matrix
    const Eigen::MatrixXd& C, // output matrix
    const Eigen::MatrixXd& Q, // covariance matrix, process noise
    const Eigen::MatrixXd& R, // covariance matrix, measurement noise
    const Eigen::MatrixXd& P) // covariance matrix, error estimate
  : A(A), C(C), Q(Q), R(R), P0(P),  // constructor initialize of private variables 
    m(C.rows()), n(A.rows()), dt(dt), initialized(false),
    I(n, n), x_hat(n), x_hat_new(n)
{
  I.setIdentity();
}

KalmanFilter::KalmanFilter() {}

void KalmanFilter::init(double t0, const Eigen::VectorXd& x0) {
  x_hat = x0;
  P = P0;
  this->t0 = t0;
  t = t0;
  initialized = true;
}

void KalmanFilter::init() {
  x_hat.setZero();
  P = P0;
  t0 = 0;
  t = t0;
  initialized = true;
}

void KalmanFilter::update(const Eigen::VectorXd& y) {

  if(!initialized)
    throw std::runtime_error("Filter is not initialized!");

  x_hat_new = A * x_hat;
  P = A*P*A.transpose() + Q;
  K = P*C.transpose()*(C*P*C.transpose() + R).inverse();
  x_hat_new += K * (y - C*x_hat_new);
  P = (I - K*C)*P;
  x_hat = x_hat_new;

  t += dt;
}

void KalmanFilter::update(const Eigen::VectorXd& y, double dt, const Eigen::MatrixXd A) {

  this->A = A;
  this->dt = dt;
  update(y);
}
