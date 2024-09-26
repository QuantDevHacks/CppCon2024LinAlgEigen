#include "Declarations.h"

#include <Eigen/Dense>

#include <iostream>

using std::cout;

void standard_operators()		// Top calling function
{
	cout << "***** standard_operators() Top calling function *****\n";
	matrix_product();
	scalar_multiplication();
	addition_subtraction();
	compute_expression();

}

void matrix_product()
{
	cout << "*** matrix_product() ***\n";
	using Eigen::MatrixXd;

	MatrixXd A
	{
		{1.0, 2.0, 3.0},
		{1.5, 2.5, 3.5},
		{4.0, 5.0, 6.0},
		{4.5, 5.5, 6.5},
		{7.0, 8.0, 9.0}
	};

	MatrixXd B
	{
		{1.0, 2.0, 3.0, 4.0, 5.0},
		{1.5, 2.5, 3.5, 4.5, 5.5},
		{5.0, 6.0, 7.0, 8.0, 8.5}
	};

	MatrixXd prod_ab = A * B;		// Eigen::Product<Matrix<double,...>, Matrix<double,...>> type
	cout << "A (5 x 3) * B (3 x 5) = \n\n" << prod_ab << "\n";

	cout << "\n\n";
}

void scalar_multiplication()
{
	cout << "*** scalar_multiplication() ***\n";
	using Eigen::MatrixXd;

	MatrixXd A
	{
		{1.0, 2.0, 3.0},
		{1.5, 2.5, 3.5},
		{4.0, 5.0, 6.0},
		{4.5, 5.5, 6.5},
		{7.0, 8.0, 9.0}
	};

	MatrixXd scale_a = 0.5 * A;
	cout << "Scalar multiplication: 0.5 * A:\n";
	cout << scale_a << "\n\n";

	MatrixXd B
	{
		{1.0, 2.0, 3.0, 4.0, 5.0},
		{1.5, 2.5, 3.5, 4.5, 5.5},
		{5.0, 6.0, 7.0, 8.0, 8.5}
	};

	B *= 2.0;
	cout << "Scaled B matrix: 2.0 * B:\n";
	cout << B << "\n\n";

	cout << "\n\n";

}

void addition_subtraction()
{
	using Eigen::MatrixXd;
	cout << "*** addition_subtraction() ***\n";

	MatrixXd A
	{
		{1.0, 2.0, 3.0},
		{1.5, 2.5, 3.5},
		{4.0, 5.0, 6.0},
		{4.5, 5.5, 6.5},
		{7.0, 8.0, 9.0}
	};

	MatrixXd C
	{
		{10.0, 20.0, 30.0},
		{10.5, 20.5, 30.5},
		{40.0, 50.0, 60.0},
		{40.5, 50.5, 60.5},
		{70.0, 80.0, 90.0}
	};

	MatrixXd mtx_sum = A + C;
	cout << "Sum of matrices A + C =:\n";
	cout << mtx_sum << "\n\n";

	MatrixXd mtx_diff = C - A;
	cout << "Difference of matrices C - A =:\n";
	cout << mtx_diff << "\n\n";

}

void compute_expression()
{
	using Eigen::MatrixXd, Eigen::VectorXd;
	cout << "*** compute_expression() ***\n";

	MatrixXd A
	{
		{10.0, 20.0},
		{30.0, 40.0}
	};

	MatrixXd B
	{
		{0.1, 0.2},
		{0.3, 0.4}
	};

	MatrixXd C
	{
		{8.74, 58.63},
		{10.6, 4.19}
	};

	VectorXd u{{5.315, 7.207}};
	VectorXd v{{0.3, 0.11}};

	VectorXd w = A * u + B * v;
	MatrixXd M = A * B + u.dot(v) * C;		// u.dot(v): dot product uv

	// Will not compile, since u and are both column vectors:
	//double dot_prod = u * v;

	cout << "Resultant Vector:\n" << w << "\n\n";
	cout << "Resultant Matrix:\n" << M << "\n\n";
}

