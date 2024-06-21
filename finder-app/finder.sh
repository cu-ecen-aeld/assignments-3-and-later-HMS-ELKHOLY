#!/bin/bash

touch errCnount.txt
r0=$(find $1 -type f 2> errCnount.txt )

 r2=$( cat errCnount.txt | wc  -c  )

if [ $r2 -eq 0 ]; then
       r0=$(find $1 -type f   | wc -l  ) 
       echo -n "The number of files are " $r0  
	echo " and the number of matching lines are" $(cat  $(find $1 -type f ) | grep $2 | wc -l)
#        echo aaaaaaaaaaaaa
        rm  errCnount.txt
        exit 0
else
        echo "error"
        rm errCnount.txt
exit 1

fi

#r1=$(echo "The number of files are " $r0  -n  )



 #r2=$( cat errCnount.txt | wc  -c 
#echo"and the number of matching lines are" $(cat  $(find $1 -type f ) | grep $2 | wc -l) 2> /dev/null)


#cat  $(find $1 -type f ) | grep $2
