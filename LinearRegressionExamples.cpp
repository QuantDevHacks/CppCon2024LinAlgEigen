#include "Declarations.h"

#include <Eigen/Dense>

#include <utility>
#include <iostream>

// See Eigen documentation:
// https://eigen.tuxfamily.org/dox/group__LeastSquares.html

using std::cout;

void linear_regression_examples()	// Top calling function
{
	regression_qr_with_intercept();
	regression_svd_with_intercept();
}

std::pair<Eigen::MatrixXd, Eigen::VectorXd> get_reg_data_with_intcpt()
{
	using Eigen::MatrixXd, Eigen::VectorXd;

	MatrixXd X{30, 4};
	X.col(0) = Eigen::VectorXd::Ones(30);

	X.col(1) = VectorXd
	{
		{
			-0.044700388, -0.007888394, 0.042980064, 0.016416586, -0.01779658, -0.016714149,
			0.019472031, 0.029853293, 0.023126097, -0.033879088, -0.00338369, -0.018474493,
			-0.012509815, -0.01834808, 0.010626754, 0.036669407, 0.010811115, -0.035571742,
			0.027474007, 0.005406069, -0.010159427, -0.006145632, -0.0103273, -0.010435171,
			0.011127197, -0.023793709, -0.028009362, 0.00218235, 0.008683152, 0.001440032
		}
	};

	X.col(2) = VectorXd
	{
		{
			-0.019002703, 0.026036835, 0.03782709, 0.010629292, -0.008382267, 0.001121697,
			-0.004494407, 0.017304537, -0.006106293, 0.012174645, -0.003305029, 0.027219671,
			-0.036089287, -0.00222959, -0.015748493, -0.02061919, -0.011641386, 0.023148757,
			-0.002290732, 0.006288094, -0.012038397, -0.029258743, 0.011219297, -0.008846992,
			-0.033738048, 0.02061908, -0.012077677, 0.015672887, 0.041012907, 0.052195282
		}
	};

	X.col(3) = VectorXd
	{
		{
			-0.030629136, 0.024918984, -0.001715798, 0.008561614, 0.003406931, -0.010823864,
			-0.010361097, -0.009302434, 0.008142014, -0.004064208, 0.000584335, 0.004640294,
			0.031893332, -0.013544321, -0.023573641, -0.004665085, -0.006446259, -0.005311412,
			0.045096308, -0.007374697, -0.00514201, -0.001715798, -0.005176363, -0.002884991,
			0.002309361, -0.014521608, -0.017711709, 0.001192088, -0.00238233, -0.004395918
		}
	};

	VectorXd Y{30};	// 30 observations 
	Y <<
		-0.039891316, 0.00178709, -0.0162018, 0.056452057, 0.00342504, -0.012038314,
		-0.009997657, 0.013452043, 0.013485674, -0.007898137, 0.008111428, -0.015424523,
		-0.002161451, -0.028752191, 0.011292655, -0.007958389, -0.004002386, -0.031690771,
		0.026776892, 0.009803957, 0.000886608, 0.01495181, -0.004155781, -0.001535225,
		0.013517306, -0.021228542, 0.001988701, -0.02051788, 0.005841347, 0.011248933;

	// If you want to inspect X and Y:
	//cout << "Design Matrix X is:\n" << X << "\n\n";
	//cout << "Response Vector Y is:\n" << Y << "\n\n";

	return std::pair<MatrixXd, VectorXd>{X, Y};
}

void regression_qr_with_intercept()
{
	cout << "*** regression_qr_with_intercept() ***\n";
	using Eigen::MatrixXd, Eigen::VectorXd;

	auto data = get_reg_data_with_intcpt();
	MatrixXd X = data.first;
	VectorXd Y = data.second;

	VectorXd beta = X.householderQr().solve(Y);
	cout << "Beta estimates from Householder QR decomposition (with intercept):\n" << beta << "\n\n";
}

void regression_svd_with_intercept()
{
	cout << "*** regression_svd_with_intercept() ***\n";
	using Eigen::MatrixXd, Eigen::VectorXd;

	auto data = get_reg_data_with_intcpt();
	MatrixXd X = data.first;
	VectorXd Y = data.second;

	// The following uses the compact SVD, indicated by the parameter Eigen::ComputeThinU | Eigen::ComputeThinV
	// See also Proposition 3.5, https://rich-d-wilkinson.github.io/MATH3030/3-3-linalg-SVD.html
	Eigen::BDCSVD<MatrixXd> svd{X, Eigen::ComputeThinU | Eigen::ComputeThinV};
	VectorXd beta = svd.solve(Y);

	cout << "Beta estimates from Bidiagonal Divide and Conquer SVD (with intercept):\n" << beta << "\n\n";
}

