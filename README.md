# fractions-c
A library to calculate with fractions in C

This library helps if you need to calculate fractions from integers. 

It contains the following elements and methods.

------------------------------------------------

    frac * newFrac(int divident, int divisor);
    
* Returns a pointer to a struct frac which represents: $$\frac{divident}{divisor}$$
* Exits in case memory can't be allocated

---------------------------------------------
    
    void printFrac(frac * self);
    
* prints the fraction as (divident/divisor)
* if divident xor divisor less than 0 it will print -(divident/divisor)

---------------------------------------------

    char * toString(frac* self, char * result);
    
* transformes the fraction to a char * with the format (divident/divisor)
* the returned pointer can is only needed for nested functioncalls
----------------------------------------------

    frac * shorten(frac * toShorten);
    
* checks if a fraction can be shortened
* transforms $$\frac{c\cdot x}{c\cdot y}$$ to $$\frac{x}{y}$$ if c != 1 
* returns pointer to toShorten with the new values 
 (you may ignore the returned pointer since the values are changed directly in the given frac.
 It is helpfull for nested functionscalls)


---------------------------------------------

    void unifyFrac(frac * toUnify, frac * toLook);

* transforms two fracs to have the same divisor (necessary for addition and substraction)

---------------------------------------------

    frac * reciprocal(frac * original);
* returns a new struct frac representing the reciprocal of the given fraction



---------------------------------------------

    frac * multiplyFrac(frac * factor_1, frac * factor_2);
    
* multiplies two fractions and returns a pointer to a new struct containing the result

-------------------------------------------

    int compareFrac(frac * first, frac * second);
    
* returns 0 if first == second
* returns 1 if first > second
* returns -1 if first < second

-----------------------------------------

    frac * sumFrac(frac * summand_1 , frac * summand_2);
    
* returning a pointer to struct frac containing the result of summand_1 + summand_2

---------------------------------------

    frac * subFrac(frac * minuent, frac * subtrahent);
    
* returning a pointer to struct frac containing the result of minuent-subtrahent


--------------------------------------

    frac * multiplyFrac(frac * factor_1, frac * factor_2);
    
* returning a pointer to struct frac containing the result of factor_1 * factor_2

--------------------------------------

    frac * divideFrac(frac * divid, frac * divis);
    
* returning a pointer to struct frac containing the result of divid/divis

------------------------------------

#### Examples:

##### Creating the fraction  a=(1000/2000) and b=2/3:
    frac * a = newFrac(1000,2000);

##### Transform (1000/2000) to (1/2):
    shorten(a);
>returned pointer is ignored!

##### Storing a as string:

    char result[100];
    toString(a, result);

##### Printing a:

    printFrac(a);
or:

    char result[100];
    printf("%s",toString(a,result));

##### Comparing a and b:

    int compared = compareFrac(a,b);
    
##### Adding b to a:
    frac * c = sumFrac(a,b);
    
##### Substracting b from c:
    frac * d = subFrac(c,b);
    
##### Multiply a and b:
    c = multiplyFrac(a,b);
    
##### Dividing c by b:
    d = divideFrac(c,b);
    
##### Transform a and b to have the same divisor:
    unifyFrac(a,b);
    
##### Get the reciprocal of a:
    d = reciprocal(a);
    
##### Mixed example:

    char result[50];
    char result2[50];
    char result3[50];
    frac * a;
    frac * b;
    frac * c = sumFrac(a=newFrac(1,-2),b=newFrac(-1,4));
    frac * d;
    frac * e = multiplyFrac(c, d=newFrac(5,100));
    printf("%s + %s = %s\n", toString(a,result),toString(b,result2),toString(c,result3) );
    printf("%s * %s = %s\n", toString(c,result),toString(d,result2),toString(e,result3) );
    printf("Shortening (5/100): %s\n",toString(shorten(d),result));
> prints: 
>   -(4/8) + -(2/8) = -(6/8)
>   -(6/8) * (5/100) = -(30/800)
>   Shortening (5/100): (1/20)
    






