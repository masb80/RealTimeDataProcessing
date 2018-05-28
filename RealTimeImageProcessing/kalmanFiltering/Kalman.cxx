#include <iostream>

#include "Kalman.h"
// x_k = A x_k-1 + B u_k-1 + w_k-1 // state x equations
// z_k = H x_k + v_k // measurement model
// p(w) ~ N(0,Q) // normal probability
// p(v) ~ N(0,R) // normal probability
// x_k = x_k^- + K(z_k - H x_k^-) // posterior state = prior state + weighted difference between actial and measurement
//K_k = p_k^- H^T ( H P_k^- H^T + R)^-1

// Summary:
// initial guess: x_k-1 and p_k-1
//Time updates - preidct
//1) x_^- = f(x_k-1, u_k-1, 0) //project the state ahead
//2) P_k^- = A_k P_k-1 A_k^T + W _K Q_k-1 W_T^K // project the error covariance ahead

// Measuremnet update - correct
// 1) compute the Kalman gain
//K_k = p_k^- H^T ( H P_k^- H^T + R)^-1
//2) x_k = x_k^- + K(z_k - H x_k^-) // update estimate with measurement z_k
// update the error covarience
// P_k = (I - K_k H_k)P_k^-
namespace myStd
{
	Kalman::Kalman() {}
	Kalman::Kalman( // constructor initialization
			double dt,
			const Eigen::MatrixXd& A, // syatem dynamics matrix, assume const but change in every time step
			const Eigen::MatrixXd& C, // output matrix
			const Eigen::MatrixXd& Q, // covariance matrix, process noise w_k , assume const here but change each time step
			const Eigen::MatrixXd& R, // covariance matrix, measurement noise v_k assume const here but change each time step
			const Eigen::MatrixXd& P) // covariance matrix, error estimate
		: A(A), C(C), Q(Q), R(R), P0(P),  // constructor initialize of private variables 
		m(C.rows()), n(A.rows()), dt(dt), initialized(false),
		I(n, n), x_hat(n), x_hat_new(n)
	{
		I.setIdentity();
	}


	void Kalman::initGuess(double t0, const Eigen::VectorXd& x0) {
		x_hat = x0;
		P = P0;
		this->t0 = t0;
		t = t0;
		initialized = true;
	}

	/*
	   void Kalman::init() {
	   x_hat.setZero();
	   P = P0;
	   t0 = 0;
	   t = t0;
	   initialized = true;
	   }
	 */

	void Kalman::filter(const Eigen::VectorXd& y) {
		// main Kalman algorithm
		if(!initialized)
			throw std::runtime_error("Filter is not initialized!");

		x_hat_new = A * x_hat; // x_k = x_k-1
		P = A*P*A.transpose() + Q; // P = APA^- + Q , error covariance
		K = P*C.transpose()*(C*P*C.transpose() + R).inverse(); // Kalman gain
		x_hat_new += K * (y - C*x_hat_new); // update x_k
		P = (I - K*C)*P; // update error covariance matrix
		x_hat = x_hat_new;

		t += dt;
	}


	void Kalman::filterUpdate(const Eigen::VectorXd& y, double dt, const Eigen::MatrixXd A) {

		this->A = A;
		this->dt = dt;
		filter(y);
	}

}
