#include "frac.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern frac * newFrac(int divident, int divisor)
{
    if(divisor==0)
    {
        printf("Division by zero not allowed\nExiting!\n");
        exit(-1);
        
    }
    frac *toCreate = malloc(sizeof(frac));
    if (toCreate != NULL)
    {
        toCreate -> divident = divident;
        toCreate -> divisor = divisor;
    }
    else
    {
        printf("Couldn't allocate Memory! Exiting!");
        exit(-1);
    }
    return toCreate;
}  

extern void printFrac(frac * self)
{
    if((self->divident>=0 && self->divisor>0))
    {
        printf("(%d/%d)", self->divident, self->divisor);
    }
    else if ((self->divident<0 && self->divisor<0))
    {
        printf("(%d/%d)", self->divident*-1, self->divisor*-1);
    }
    else if (self->divisor<0)
    {
        printf("-(%d/%d)", self->divident, self->divisor*-1);
    }
    else if(self->divident<0)
    {
        printf("-(%d/%d)", self->divident*-1, self->divisor);
    }
}    

extern frac * multiplyFrac(frac * factor_1, frac * factor_2)
{
    if(factor_1->divident<0 && factor_1->divisor<0)
    {
        factor_1->divident=factor_1->divident*-1;
        factor_1->divisor = factor_1->divisor*-1;
    }
    if(factor_2->divident<0 && factor_2->divisor<0)
    {
        factor_2->divident=factor_2->divident*-1;
        factor_2->divisor = factor_2->divisor*-1;
    }
    int x = factor_1->divident * factor_2->divident;
    int y = factor_1->divisor * factor_2->divisor;
    
    frac * result = newFrac(x,y);
    return result;
}

extern frac * reciprocal(frac * original)
{
    int x = original->divisor;
    int y = original->divident;
    return newFrac(x,y);
}
extern frac * divideFrac(frac * divid, frac * divis)
{
    frac * reciproc = reciprocal(divis);
    frac * result = multiplyFrac(divid, reciproc);
    return result;
}

extern void unifyFrac(frac * toUnify, frac * toLook)
{
    if(toUnify->divisor != toLook->divisor)
    {
        int x1 = toUnify->divident * toLook->divisor;
        int y1 = toUnify->divisor * toLook->divisor;
        int x2 = toLook->divident * toUnify->divisor;
        int y2 = toLook->divisor * toUnify->divisor;
    
        toUnify->divident=x1;
        toUnify->divisor=y1;
        toLook->divident=x2;
        toLook->divisor=y2;
    }
    
}
extern frac * shorten(frac * toShorten)
{
    int x = toShorten->divident;
    int y = toShorten->divisor;
    int i;
    if(x>=0)
    {
        for(i=x; i>1; i--)
        {
            if(y % i ==0 && x%i ==0)
            {
                toShorten->divident=x/i;
                toShorten->divisor=y/i;
                break;
            }
        }
    }
    else
    {
        for(i=x*-1; i>1; i--)
        {
            if(y % i ==0 && x%i ==0)
            {
                toShorten->divident=x/i;
                toShorten->divisor=y/i;
                break;
            }
        }
    }
    
    return toShorten;
}
extern char * toString(frac* self, char * result)
{
    
    if((self->divident>=0 && self->divisor>0))
    {
        snprintf(result, 1024, "(%d/%d)", self->divident, self->divisor);
    }
    else if ((self->divident<0 && self->divisor<0))
    {
        snprintf(result, 1024, "(%d/%d)", self->divident, self->divisor);
    }
    else if (self->divisor<0)
    {
        snprintf(result, 1024, "-(%d/%d)", self->divident, self->divisor*-1);
    }
    else if(self->divident<0)
    {
       snprintf(result, 1024, "-(%d/%d)", self->divident*-1, self->divisor);
    }
    
    return result;
}
extern frac * sumFrac(frac * summand_1 , frac * summand_2)
{
    unifyFrac(summand_1,summand_2);
    frac * sum = newFrac(summand_1->divident+summand_2->divident, summand_1->divisor); 
    return sum;
    
}
extern frac * subFrac(frac * minuent, frac * subtrahent)
{
    unifyFrac(minuent,subtrahent);
    frac * difference = newFrac(minuent->divident - subtrahent->divident, minuent->divisor);
    return difference;
}
extern int compareFrac(frac * first, frac * second)
{
    int i;
    unifyFrac(first,second);
    if(first->divident<second->divident)
    {
        i=-1;
    }
    else if(first->divident>second->divident)
    {
        i=1;
    }
    else if(first->divident==second->divident)
    {
        i=0;
    }
    shorten(first);
    shorten(second);
    return i;
}
