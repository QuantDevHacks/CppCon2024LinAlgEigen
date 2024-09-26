#define MDSPAN_USE_PAREN_OPERATOR 1
#include "Declarations.h"

#include <experimental/mdspan>
#include <experimental/linalg>
#include <vector>
#include <iostream>

int main()
{
	create_eigen_matrix_and_vector_types();
	standard_operators();
	stl_compatibility();
	linear_regression_examples();
	std_blas_and_Eigen();
}

