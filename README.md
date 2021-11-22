# Ode Solver

Ode Solver for Advanced Programming Project.

Contributors: Vikas Kurapati <vikas.kurapati@tum.de> and Nikhita Kurupakulu Venkat <nikhita.venkat@tum.de>. Group AH
 
 ## Table of contents

 ### General Idea
 This is a solver for an Ordinary Differential Equation problem. Explicit and Implicit Euler schemes are used to solve the Ordinary Differential Equations. 

 ### Instructions for use
 1. Enter the gradient function, initial value of function, total time duration and time step.
 2. The gradient is to be input as a lamba function which is a function of x, t. x is the variable being solved for and t is the independent variable.
 3. For example, $`\frac{dx}{dt} = e^t`$ is shown here. $`\frac{dx}{dt} = e^x`$ would return $`e^x`$.
 4. To run the case you choose, run command: "make" and then run the executable ./main to run the program
 5. To run the test cases, run command: "make test" and then run the executable ./test to run the program
 6. Run the command "make clean" in case you want to delete the executables and the object files.