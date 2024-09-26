#include "Declarations.h"

#include <Eigen/Dense>

#include <vector>
#include <numeric>
#include <algorithm>
#include <ranges>
#include <random>
#include <iostream>

using std::cout;

void stl_compatibility()		// Top calling function
{
	cout << "***** stl_compatibility() Top calling function *****\n\n";
	max_elem_vector_xd();
	stl_vec_and_vector_xd();
	unary_expressions();
}

void max_elem_vector_xd()
{
	cout << "*** max_elem_vector_xd() ***\n";
	using Eigen::VectorXd;

	VectorXd u{12}; 
	std::mt19937_64 mt{100}; 
	std::student_t_distribution<> tdist{5}; 
	std::generate(u.begin(), u.end(), [&mt, &tdist]() {return tdist(mt);});

	auto max_u = std::max_element(u.begin(), u.end());

	cout << "Contents of VectorXd u:\n";
	for (const auto& x : u) {cout << x << " ";}
	cout << "\n Max element = " << *max_u << "\n\n";
}

void stl_vec_and_vector_xd()
{
	cout << "*** stl_vec_and_vector_xd() ***\n";
	using Eigen::VectorXd;

	VectorXd u{12};
	std::mt19937_64 mt{100};
	std::student_t_distribution<> tdist{5};

	// u is a VectorXd, v is an STL vector
	std::vector<double> v(u.size());	// u is a VectorXd, v is an STL vector 	
	std::generate(u.begin(), u.end(), [&mt, &tdist]() {return tdist(mt);});
	std::generate(std::begin(v), std::end(v), [&mt, &tdist]() {return tdist(mt);});


	// Example 1:  Dot (inner) product of Eigen::VectorXd and std::vector:
	cout << "Contents of VectorXd u:\n";
	for (const auto& x : u) {cout << x << " ";}
	cout << "\nContents of std::vector v:\n";
	for (const auto& x : v) {cout << x << " ";}

	// Inner product of Eigen::VectorXd and std::vector
	double dot_prod = std::inner_product(u.begin(), u.end(), v.begin(), 0.0);
	cout << "\n Dot (inner) product of u & v: " << dot_prod << "\n\n";

	// Example 2:  Element-by element addition of Eigen::VectorXd and std::vector, using ranges form of std::transform:
	VectorXd w(v.size());
	std::ranges::transform(u, v, w.begin(), std::plus{});

	cout << "Result of element-by element addition of u & v:\n";
	for (const auto& x : w) {cout << x << " ";}

	cout << "\n\n";
}

void unary_expressions()
{
	cout << "*** unary_expressions() ***\n";

	// Eigen function similar to std::transform

	using Eigen::MatrixXd;

	MatrixXd vals
	{
		{9.0, 8.0, 7.0},
		{3.0, 2.0, 1.0},
		{9.5, 8.5, 7.5},
		{3.5, 2.5, 1.5}
	};

	cout << "Original matrix:\n\n" << vals << "\n\n";

	vals = vals.unaryExpr([](double x) {return x * x;});

	cout << "Result of unaryExpr(.) applied to matrix:\n\n" << vals;

	cout << "\n\n";
}