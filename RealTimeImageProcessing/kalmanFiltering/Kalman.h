#ifndef KALMAN_H_
#define KALMAN_H_
#include <Eigen/Dense>

#pragma once

namespace myStd
{
	class Kalman
	{

		public:

			Kalman();
			Kalman(
					double dt,
					const Eigen::MatrixXd& A,
					const Eigen::MatrixXd& C,
					const Eigen::MatrixXd& Q,
					const Eigen::MatrixXd& R,
					const Eigen::MatrixXd& P
			      );


			//void init();

			void initGuess(double t0, const Eigen::VectorXd& x0);

			void filter(const Eigen::VectorXd& y);

			void filterUpdate(const Eigen::VectorXd& y, double dt, const Eigen::MatrixXd A);

			Eigen::VectorXd state() { return x_hat; };
			double time() { return t; };

		private:

			Eigen::MatrixXd A, C, Q, R, P, K, P0;

			int m, n;

			double t0, t;

			double dt;

			bool initialized;

			Eigen::MatrixXd I;

			Eigen::VectorXd x_hat, x_hat_new;
	};
}
#endif
