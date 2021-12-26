# Ode Solver

Ode Solver for Advanced Programming Project.

Contributors: Vikas Kurapati <vikas.kurapati@tum.de> and Nikhita Kurupakulu Venkat <nikhita.venkat@tum.de>. Group AH
 
 ## Table of contents

 ### General Idea
 This is a solver for an Ordinary Differential Equation problem. Explicit Euler and Implicit Euler schemes are implemented to solve the Ordinary Differential Equations. More schemes will be added in the future. 

 ### Instructions for use
 1. Navigate to the src folder by typing `cd src`, enter the gradient function in the code "main.cpp"(will be changed in the later stages of the project)(We still couldn't come up with a better idea to do this. Any suggestions in the form of a pull request are welcome), initial value of function, total time duration and time step are taken as inputs during the run time.
 2. The gradient is to be input as a lamba function which is a function of y, t. y is the variable being solved for and t is the independent variable.
 3. For example, $`\frac{dy}{dt} = e^t`$ is shown here. $`\frac{dy}{dt} = e^x`$ would return $`e^x`$.
 4. To run the case you choose, navigate to the build directory by typing
```
cd ../build
```
 5. After navigating to the build directory, run the below command to make the build files(this need not be run again once the build files are made unless the code structure is changed): 
```
cmake ../src/
```
 6. After the cmake is ran,  then run the below command to create the executables(this need not be run again once the executables are created unless the code is changed)
```
make
``` 
 7. To run the case you chose, run 
```
./main
```
 8. To view the solution file, open: `solution.txt` file in the same folder.

 9. To run the test cases, run command 
```
./solver-test
```

 10. Run the command `make clean` in case you want to delete the executables and the object files.
