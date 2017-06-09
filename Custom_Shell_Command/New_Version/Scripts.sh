var="`ps ax`"

echo "$var"

destdir=/home/smn/Desktop/dir.txt

if [ -f "$destdir" ]
then
echo "$var" > "$destdir"
fi


echo "enter filter: "
read filter

./a.out $filter


