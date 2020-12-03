#include "hamming1.h"

/**
 *  @file hamming1
 *  m_size is the length of data bits
 *  msg[50] is data bits transmitted
 *  data[60] is the generated data bits which consists of errors
 */
 int mult(int rbit)
{

    int ret=1,i;
    for(i=0;i<rbit;i++)
    {
        ret=ret*2;
    }
    return ret;
}
int * hamming1(int msg[],int m_size,int data1[])
{
    //int a=5;
    //printf("%d",a);
    int rbit=0,data[60],cnt,even,i,j,k;

/** calculate no. of rbits (parity bits)
 *  2^r > m_size + rbit + 1
 */

while(1)
{
    if((m_size+rbit+1) <= mult(rbit))  //if this condition    2^r > m_size + rbit + 1 fails then break
        break;
    rbit++;                          //calculating no. of bits
}

/**now we are creating array for data   in this we are assigning 8 at rbit position and assigning message values at other positions
 *  so the total data will be of size * m_size+rbit
 *  here we are taking k for referencing of finding 2^k so k=0
 *  and j for pointing to msg value at certain position j=1
*/

k=0;
j=1;
for(i=1;i<=(m_size+rbit);i++)
{
    if(i==mult(k))
    {
        data[i]=8;
        k++;                //we are incrementing k for pointing to next rbit position
    }
    else
    {
        data[i]=msg[j];     //assigning
        j++;                //increment j++ to point at next position
    }
}

/**now we have to cal value of rbit's so
     *r1 = 1+3+5+7+9...
     *r2 = 2+3+6+7+10+11...
     *r4 = 4+5+6+7+12+13...
     *r8 = 8+9+10+11+12+13+14...
     *here we are calculating addition so let us consider that we are checking no of one's(var) available if(var%2==0) then
     *data[i]=1
*/
for(i=1;i<=(m_size+rbit);i++)       // or all values
{
    if(data[i]==8)                  //value is 8 where there is position of rbit
    {
        data[i]=0;             //change value of data[i] from 8 to 0
        even=0;
        for(j=1;j<=(m_size+rbit);j++)
        {
            for(k=0;k<i;k++)
            {
                if(data[j]==1)
                {
                    even++;
                }
                j++;
            }
            j=j+i-1;
        }
        if(even%2==0)
        {
            data[i]=0;
        }
        else
        {
            data[i]=1;
        }
    }
}

/** suppose an example
    *   m_size=6
    *   msg = 1 0 1 1 1 1
    *   rbit = 4
    *   data array = 4+6 = 10

    *   1 2 3 4 5 6 7 8 9 10
    *   p p 1 p 0 1 1 p 1 1   data with p as parity position
    *   1 0 1 0 0 1 1 0 1 1   data with calculated parity
    *   for p at position 1 : then data[1]=0 even= 0+1+0+1+1+1              data[1]=1
    *   for p at position 2 : then data[2]=0 even= 2+3+6+7+10= 0+1+1+1+1=0  data[2]=0
    *   for p at position 3 : then data[3]=0 even= 4+5+6+7 = 0+0+1+1        data[3]=0
    *   for p at position 4 : then data[4]=0 even=8+9+10 =0+1+1             data[4]=0
*/
cnt=0;
for(i=1;i<=(m_size+rbit);i++)
{
    if(i==mult(cnt))
    {
        cnt++;
        even=0;
        for(j=1;j<=(m_size+rbit);j++)
        {
            for(k=0;k<i;k++)
            {
                if(data1[j]==1)
                {
                    even++;
                }
            j++;
            }
        j=j+i-1;
        }
    if(data1[i]==1)
    {
        even--;
    }
    if(even%2==0 && data1[i]==1)
    {
        data1[i]=0;
        break;
    }
    if(even%2==1 && data1[i]==0)
    {
        data1[i]=1;
        break;
    }
    }
}
return data1;
}




