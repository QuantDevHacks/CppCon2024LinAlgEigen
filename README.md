# CppCon2024LinAlgEigen

This code accompanies the CppCon 2024 talk "Linear Algebra with The Eigen C++ Library".  There are additional examples along with code examples shown during the presentation. 

The reference implementation of stdBLAS (plus `mdspan`) is also included in the repository.  It works in Visual Studio 2022 if you include the kokkos directory as a subdirectory in your project.  You will also need the Eigen header files (header-only library), available here: https://eigen.tuxfamily.org/

So, if your project name is `SampleCode`, then you should place the following in your include path:
`c:\SampleCode\kokkos`
`c:\YourLibraries\eigen-3.4.0`

Also, if using Visual Studio, in your project settings, make sure to:
1. Use the most recent compiler
2. Use the Clang compiler option (the stdBLAS code will not compiler with the VS compiler)

Some supplemental information:

Eigen in quantitative finance (Quantstart article): https://www.quantstart.com/articles/Eigen-Library-for-Matrix-Algebra-in-C

Eigen chosen for ATLAS Experiment (CERN) tracking software:  https://iopscience.iop.org/article/10.1088/1742-6596/608/1/012047/pdf
