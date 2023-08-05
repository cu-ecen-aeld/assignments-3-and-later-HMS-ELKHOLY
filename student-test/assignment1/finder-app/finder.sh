read filesdir
read searchstr
let i=0
for line in $( find $searchdir) ; do 
	echo $line
	let i=i+1
done

echo $i
