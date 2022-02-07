# Performance

 ## Gprof
 gprof.log doesn't show any functions with significant overhead 

 ## Pahole
 Class members weren't aligned earlier but now aligned. Pahole shows some alerts for methods but they were not changed. 

 ## Optimizations performed
 1. Replaced divisions with multiplications wherever possible
 2. Prevented square roots by comparing squares of functions
 3. Replaced string types with string_view wherever possible
 4. Modified some simple functions into their inline methods
 5. Added the -O3 flag in the CMake to add any hidden optimizations

 ## Performance 
 1. Before optimization: Explicit Method: 0m3.511s. After optimiation: 0m2.511s
 2. Before optimization: Implicit Method: 0m5.511s. After optimization: 0m3.684s

 As the implementation is fairly simple and for only one dimensional, there weren't any opportunities for auto-vectorization and significant improvements.