# Project 1 Report #
## Input and Results from Step 5: ##
-	To start, I inputted 0 for the number of seats held by Democrats, Republicans, and Independents. The result displayed nan% Republicans, nan% Democrats, nan% Independents, and “Looks like control goes to the Democrats.” This is nonsensical in the sense that the program should indicate 0.0% for each party, and control should not go to the democrats because they have no majority.
-	A similar result was produced when I input 210 for Democrats, 210 for Republicans, and 15 for Independents. The program gave correct percentages for each party, but it still outputted “Looks like control goes to the Democrats”, which is not the case because the Democrats and Republicans have equal numbers of seats.
-	When I inputted 20 for Democrats, 20 for Republicans, and 395 for Independents, the result displayed the correct percentages of seats held for each party, but said “Looks like control goes to the Democrats”, though control should actually go to the independent representatives.
-	Lastly, when the inputted integers for the three groups do not add up to 535 (the total number of seats in Congress), the program does not complain; rather it gives the percentages of seats held by each party out of the sum of the input integers. This is nonsensical because the percentages should be out of a total of 535.


## Error Introduced into logic_error.cpp Program: ##
-	The error I introduced into the logic_error project file was changing the line ```int total = republicanSeats + democraticSeats + independentSeats;``` to ```int total = republicanSeats + democraticSeats;```
-	Deleting the variable “indepentSeats” from the phrase gives an incorrect value for the integer total, which means that even though the program is still able to build, the outputted percentages of seats held by each party are mathematically incorrect.

## Error Introduced into compile_error.cpp Program: ##
*	The first error I introduced was changing the line ```int republicanSeats;``` to ```republicanSeats; ```, which caused the program to say “failed to build” when I tried to compile it on XCode. In the code itself, the error messages that appeared said “use of undeclared identifier ‘republicanSeats’” on every line where “republicanSeats” was written, including the line that I edited.
* The second error I introduced was changing the line ```cout << “How many seats are held by Independents?";``` to ```cout << “How many seats are held by Independents? ;```
    * Deleting the quotation mark at the end of the phrase also caused the program to fail to build. Two error messages appeared on that line: one said “expected expression” and was highlighted in red, and the other said “missing terminating ‘“‘ character” and was highlighted in yellow.
