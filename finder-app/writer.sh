
if  [ -z "$1" ]; then
echo empty 1
exit 1

fi
if  [ -z "$2" ]; then
exho empty 2
exit 1

fi
touch  errCountW.txt


mkdir  "$1"aa -p 2> errCountW.txt
w0=$( cat  errCountW.txt | wc -c)
if [ $w0 -eq 0 ]; then
rm "$1"aa -rf

touch "$1"
echo >> "$1" "$2"

rm  errCountW.txt


exit 0



else

rm  errCountW.txt
echo error

exit 1

fi
