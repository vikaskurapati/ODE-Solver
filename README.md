# Ode Solver

Ode Solver for Advanced Programming Project.

Contributors: Vikas Kurapati <vikas.kurapati@tum.de> and Nikhita Kurupakulu Venkat <nikhita.venkat@tum.de>. Group AH
 
 ## Table of contents

 ### General Idea
 This is a solver for an Ordinary Differential Equation problem. Explicit Euler schemes are used to solve the Ordinary Differential Equations. 

 ### Instructions for use
 1. Navigate to the src folder by typing `cd src`, enter the gradient function in the code "main.cpp"(will be changed in the later stages of the project), initial value of function, total time duration and time step are taken as inputs during the run time.
 2. The gradient is to be input as a lamba function which is a function of x, t. x is the variable being solved for and t is the independent variable.
 3. For example, $`\frac{dx}{dt} = e^t`$ is shown here. $`\frac{dx}{dt} = e^x`$ would return $`e^x`$.
 4. To run the case you choose, navigate to the build directory by typing
```
mkdir ../build

cd ../build
```
 5. After navigating to the build directory, run command: 
```
cmake ../src/
```
 6. After the cmake is ran,  then run the below command to create the executables 
```
make
``` 
 7. To run the case you chose, run 
```
./main
```
 8. To run the test cases, run command 
```
./solver-test
```

 9. Run the command `make clean` in case you want to delete the executables and the object files.
