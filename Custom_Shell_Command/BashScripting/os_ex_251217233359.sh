cd $1
files=`ls *.{cpp,h}`
s="/"
for i in $files; do
	if [[ -f "$1$s$i" ]]; then
		if [[ $i =~ [A-Z] ]]; then
			cp $1$s$i $2
			mv $1$s$i `echo $i | tr [:upper:] [:lower:]`
			echo "The case of "$i" has changed and copied to "$2" with primary name."
		else
			echo $i" is lowercase and nothing happened!"
		fi
	else
		echo $i" is a directory!"
	fi
done
