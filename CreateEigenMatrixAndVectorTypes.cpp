#include "Declarations.h"

#include <Eigen/Dense>
#include <iostream>

using std::cout;


void create_eigen_matrix_and_vector_types()
{
	cout << "***** create_eigen_matrix_and_vector_types() Top calling function *****\n";

	create_matrix_xd_types();
	create_vector_xd_types();
	create_matrix_xd_types_with_vector_xd_data();
}

void create_matrix_xd_types()
{
	cout << "*** create_matrix_xd_types() ***\n";

	// Note: the sample code uses different mtx names 
	// mtx01, mtx02, mtx03 so that the code will compile and run.

	using Eigen::MatrixXd;
	MatrixXd mtx01
	{
		{1.0, 2.0, 3.0},
		{4.0, 5.0, 6.0},
		{7.0, 8.0, 9.0},
		{10.0, 11.0, 12.0}
	};

	MatrixXd mtx02{4, 3}; 
	mtx02 << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0;

	MatrixXd mtx03{2, 2};
	// 0-index as is the case in C++ generally:
	mtx03(0, 0) = 3.0;
	mtx03(1, 0) = 2.5;
	mtx03(0, 1) = -1.0;
	mtx03(1, 1) = mtx03(1, 0) + mtx03(0, 1);

	cout << "mtx01:\n";
	cout << mtx01;
	cout << "\n\n";

	cout << "mtx02:\n";
	cout << mtx02;
	cout << "\n\n";

	cout << "mtx03:\n";
	cout << mtx03;
	cout << "\n\n";
}

void create_vector_xd_types()
{
	cout << "*** create_vector_xd_types() ***\n";

	// Note: the sample code uses different vec names 
	// vec01, vec02, vec03 so that the code will compile and run.

	using Eigen::VectorXd;

	VectorXd vec01{{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}};

	VectorXd vec02{6};			// 6 elements
	vec02 << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0;

	VectorXd vec03{3};			// 3 elements
	vec03(0) = 3.19;
	vec03(1) = 2.58;
	vec03(2) = vec03(0) + vec03(1);

	cout << "vec01:\n";
	cout << vec01;
	cout << "\n\n";

	cout << "vec02:\n";
	cout << vec02;
	cout << "\n\n";

	cout << "vec03:\n";
	cout << vec03;
	cout << "\n\n";
}

// Not explicitly in the slides but included here as an extra example.
// This form is used in the discussion of linear regression models
// later in the presentation:
void create_matrix_xd_types_with_vector_xd_data()
{
	cout << "*** create_matrix_xd_types_with_vector_xd_data() ***\n";

	using Eigen::MatrixXd, Eigen::VectorXd;

	MatrixXd design_mtx{10, 3};

	design_mtx.col(0) = VectorXd::Ones(design_mtx.rows());	// Column of 1's for the intercept term
	design_mtx.col(1) = VectorXd{{-0.044, -0.007, 0.043, 0.016, -0.0178, -0.017, 0.019, 0.029, 0.023, 0.011}};
	design_mtx.col(2) = VectorXd{{-0.012, -0.029, 0.011, -0.009, -0.033, 0.021, -0.012, 0.0157, 0.041, 0.052}};
	design_mtx.col(1) = VectorXd{{-0.009, 0.008, -0.004, 0.018, 0.004, 0.032, -0.013, -0.024, -0.005, -0.006}};

	cout << "Design Matrix:\n";
	cout << design_mtx;
	cout << "\n\n";

}