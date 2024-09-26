#define MDSPAN_USE_PAREN_OPERATOR 1		// For stdBLAS, to use the (i, j) operator.  
										// stdBLAS will also support (by default?) the new [i, j] operator when
										// released in C++26, but (i, j) is used for the following examples.
										// Note also, in Visual Studio, you will need to use the
										// Clang compiler option for these examples to compile and run.
#include "Declarations.h"

#include <Eigen/Dense>

#include <experimental/mdspan>
#include <experimental/linalg>
#include <vector>
#include <iostream>
#include <iomanip>

using std::vector, std::cout;
namespace stdex = std::experimental;

void simple_prod_ex()
{
	// Adapted from the example in Kokkos GitHub --
	// Simple introductory example, not in presentation slides:
	// https://github.com/kokkos/stdBLAS/blob/main/examples/02_matrix_vector_product_basic.cpp
	using std::vector, std::cout;
	namespace stdex = std::experimental;

	cout << "*** simple_prod_ex() ***\n";

	constexpr size_t N = 4;
	constexpr size_t M = 4;

	vector<int> A_vec{1, 2, 3, 4};
	vector<int> x_vec{1, 2};
	vector<int> y_vec(x_vec.size());

	stdex::mdspan A{A_vec.data(), N, M};
	stdex::mdspan x{x_vec.data(), M};
	stdex::mdspan y{y_vec.data(), N};
	stdex::linalg::matrix_vector_product(A, x, y);
}

void std_blas_and_Eigen()
{
	using std::vector, std::cout;
	using Eigen::MatrixXd;
	namespace stdex = std::experimental;

	cout << "*** std_blas_and_Eigen() ***\n";

	// Portfolio covariance matrix:
	vector cov_mtx_data	 // Cov Matrix (Sigma)
	{
		0.01263, 0.00025, -0.00017, 0.00503,
		0.00025, 0.00138,  0.00280, 0.00027,
	   -0.00017, 0.00280,  0.03775, 0.00480,
		0.00503, 0.00027,  0.00480, 0.02900
	};

	vector omega{0.25, -0.25, 0.50, 0.50};	// Vector of asset weights (omega)

	long n = omega.size();		 			// Use long types for Eigen (later)

	vector<double> inner_mtx_vec(n);		// Intermediate storage of Sigma * omega (RHS)

	// mdspan views of data (can use CTAD):
	stdex::mdspan md_cov_mtx{cov_mtx_data.data(), stdex::extents{n, n}};
	stdex::mdspan md_wgts{omega.data(), stdex::extents{n}};
	stdex::mdspan md_inner_mtx_vec{inner_mtx_vec.data(), stdex::extents{n}};

	// Compute the quadratic form using stdBLAS: 
	// 1) RHS product 1st: Sigma * omega:
	stdex::linalg::matrix_vector_product(md_cov_mtx, md_wgts, md_inner_mtx_vec);

	// 2) Now apply LHS product: omega^T * (Sigma * omega)
	double port_var = stdex::linalg::dot(md_wgts, md_inner_mtx_vec);	 // 0.02038

	cout << "\nMonthly Portfolio Variance = " << port_var << "\n\n";

	// An Eigen::Map is also a view but can be used like a MatrixXd:
	Eigen::Map<MatrixXd> cov_mtx_map{&md_cov_mtx(0, 0), n, n};

	// Create an Eigen::LLT (Cholesky Decomposition) object:
	Eigen::LLT<Eigen::MatrixXd> chol{cov_mtx_map};

	// Member function matrixL() returns the Cholesky L matrix:
	MatrixXd chol_mtx = chol.matrixL();

	cout << "Cholesky results could be stored as view in a new mdspan\n";
	cout << "but...we get upper triangular because data is column-major in Eigen:\n:";
	stdex::mdspan md_chol_mtx{chol_mtx.data(), stdex::extents{n, n}};

	cout << std::fixed << std::setprecision(6);
	for (long i = 0; i < md_chol_mtx.extent(0); ++i)
	{
		for (long j = 0; j < md_chol_mtx.extent(1); ++j)
		{
			// This will eventually be md_chol_mtx[i, j] once the 
			// multi-index square bracket operator becomes mainstream (C++23)
			cout << md_chol_mtx(i, j) << "\t";
		}

		cout << "\n";
	}

	cout << "\n\n";

	cout << "Need a column-major mdspan to store the result as lower triangular: Use layout_left...\n";
	stdex::layout_left::mapping col_major{stdex::extents{n, n}};
	stdex::mdspan md_chol_mtx_col_maj{chol_mtx.data(), col_major};

	for (long i = 0; i < md_chol_mtx_col_maj.extent(0); ++i)
	{
		for (long j = 0; j < md_chol_mtx_col_maj.extent(1); ++j)
		{
			cout << md_chol_mtx_col_maj(i, j) << "\t";
		}

		cout << "\n";
	}

	cout << "\n\n";
}