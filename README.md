# _Linear Algebra with The Eigen C++ Library_
## CppCon 2024 Sample Code

This code accompanies the CppCon 2024 talk _Linear Algebra with The Eigen C++ Library_, presented by Daniel Hanson.  There are additional examples along with code examples shown during the presentation. 

The reference implementation of stdBLAS (plus `mdspan`) is also included in the repository.  It works in Visual Studio 2022 if you include the kokkos directory as a subdirectory in your project.  You will also need the Eigen header files (header-only library), available here: https://eigen.tuxfamily.org/

So, if your project name is, for example `SampleCode`, then you should place the following in your include path:  
`c:\SampleCode\kokkos`  
`c:\YourCppLibraries\eigen-3.4.0`

Also, if using Visual Studio, in your project settings, make sure to:  
1. Use the most recent compiler  
2. Use the Clang compiler option (the stdBLAS code will not compiler with the VS compiler)  

Some supplemental resources:

* Slides from the presentation:  https://github.com/CppCon/CppCon2024/blob/main/Presentations/Linear_Algebra_with_The_Eigen_Cpp_Library.pdf
* stdBLAS reference implementation repository and information:  https://github.com/kokkos/stdBLAS  
* Eigen in quantitative finance (Quantstart article): https://www.quantstart.com/articles/Eigen-Library-for-Matrix-Algebra-in-C  
* Eigen chosen for ATLAS Experiment (CERN) tracking software:  https://iopscience.iop.org/article/10.1088/1742-6596/608/1/012047/pdf  
