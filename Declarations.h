#pragma once

#include <Eigen/Dense>
#include<utility>		// std::pair

// Create Matrix and Vector objects
void create_eigen_matrix_and_vector_types();	// Top calling function
void create_matrix_xd_types();
void create_vector_xd_types();
void create_matrix_xd_types_with_vector_xd_data();


// Operators
void standard_operators();		// Top calling function
void matrix_product();
void scalar_multiplication();
void addition_subtraction();
void compute_expression();

// STL Compatibility
void stl_compatibility();		// Top calling function
void max_elem_vector_xd();
void stl_vec_and_vector_xd();
void unary_expressions();


// Linear Regression
void linear_regression_examples();	// Top calling function
std::pair<Eigen::MatrixXd, Eigen::VectorXd> get_reg_data_with_intcpt();	// Regression Data
void regression_qr_with_intercept();
void regression_svd_with_intercept();

// stdBLAS and Eigen
void simple_prod_ex();
void std_blas_and_Eigen();


