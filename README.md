# OOPD-Assignment-4

# Q1
  # Menu options
   * 0 - show vehicle's database
   * 1 - change Vehicle no -> takes vehicle no and new vehicle no 
   * 2 - change Firstname -> takes vehicle no and new First Name
   * 3 - change Lastname -> takes vehicle no and new Last Name
   * 4 - change gender -> takes vehicle no and new gender
   * 5 - change address -> takes vehicle no and new address
   * 6 - change age -> takes vehicle no and new age
   * 7 - change Entry -> takes vehicle no , new Vehicle no, new First Name , new Last Name , new Gender and new Age
   * 8 - exit -> for exiting program

# Q2
  # Menu options
   * 0 - show vehicles voilation's database -> shows database
   * 1 - change Vehicle no -> takes vehicle no and new vehicle no
   * 2 - change source of report -> takes vehicle no and new source of report
   * 3 - change location of voilation -> takes vehicle no and new Location of Voilation
   * 4 - get details of voilation -> takes vehicle no
   * 5 - get source of report -> takes vehicle no
   * 6 - get location of voilation -> takes vehicle no
   * 7 - exit -> for exiting program
# Q3
  # Menu options
   * 0 - show reference database -> shows database
   * 1 - change Entry in database -> takes vehicle , New First name , New Last name, New Gender, New Age and New Address
   * 2 - get probable addresses -> takes vehicle no
   * 3 - exit -> for exit menu

# Q4
  # Menu options
   * 0 - show challenges database -> shows database
   * 1 - change Vehicle no -> takes Current Vehicle No and New Vehicle No
   * 2 - change Evidence info -> shows another menu in which asks what would like to change witness1 , witness2 , Location, source of voilation and response of person
   * 3 - change Complaiant info -> shows another menu in which ask what would like to change name, gender , age , address and vehicle no
   * 4 - Enter new challenge by a person -> takes details of person, witness details exactly 3 witnesses , response from person , Location and Source of voilation 
   * 5 - get past records -> takes vehicle no and shows its past records
   * 6 - getComplaiant details -> takes vehicle no and shows complainant details
   * 7 - get evidence -> takes vehicle no and shows evidence information
   * 8 - exit -> for exiting menu
# Data type
  * In all Question data type for all the things in string except age, age takes integer values

    
# Using g++ for building file
  * g++ -g Q1.cpp
  * g++ -g Q2.cpp
  * g++ -g Q3.cpp
  * g++ -g Q4.cpp

# Using Make File
  # For All Question 
   * use make all
  # For Question 1 
   * use make debug_Q1
   * use make optimization_Q1
  # For Question 2 
   * use make debug_Q2
   * use make optimization_Q2
  # For Question 3
   * use make debug_Q3
   * use make optimization_Q3
  # For Question 4 
   * use make debug_Q4
   * use make optimization_Q4