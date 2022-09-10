Name: Haley Boren
Email: hboren@usc.edu

To compile:
g++ -g -Wall ulliststr.cpp ulliststr_test.cpp -o ulliststr_test

To run: 
./ulliststr_test 

To check valgrind: 
valgrind --tool=memcheck --leak-check=yes ./ulliststr_test