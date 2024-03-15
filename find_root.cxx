# include <iostream>
# include <cmath>
# include <functional>
# include <string>
# include "function_input.h"
# include "root_finding.h"

/*
Description:
---------
Main function to find the root of a function using the chosen method.
The method is chosen by passing the method name as an argument to the program, e.g.:
./find_root bisection
./find_root newton_raphson
./find_root secant
The function to find the root of is defined in the function f, found in function_input.h and implemented in function_input.cxx.

Compilation:
-----------
To compile the program, use the following commands, where cmake is called from the build folder
to create the makefile using the "out of source" method, which keeps the source directory clean.
If recompiling, run make clean (in build folder) first and no need to recreate the build folder
mkdir build
cd build
cmake ..
make all
./find_root <method choice>
*/

int main(int argc, char* argv[]) {
  // Check if the method is passed as an argument
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <method>" << std::endl;
    return 1;
  }

  std::string method = argv[1]; // Convert char* to std::string so it can be compared easily
  std::cout << "Chosen method: " << method << std::endl;

  double root;

  if (method == "bisection" ) {
    double left_limit = 1.0;
    double right_limit = 2.0;
    double tol = 1e-6;
    int max_iter = 100;
    root = bisection(f, left_limit, right_limit, tol, max_iter);

  } else if (method == "newton_raphson") {
    double x0 = 1.0;
    double tol = 1e-6;
    int max_iter = 100;
    root = newton_raphson(f, df, x0, tol, max_iter);

  } else if (method == "secant") {
    double x0 = 1.0;
    double x1 = 2.0;
    double tol = 1e-6;
    int max_iter = 100;
    root = secant(f, x0, x1, tol, max_iter);

  } else {
    std::cout << "Invalid method." << std::endl;
    return 1;
  }

  std::cout << "Root: " << root << std::endl;
  return 0;
}