echo "enter directory: "
read directory
echo "directory saved!!"
cd $directory
var="`ls -l`"

echo "$var"

destdir=/home/smn/Desktop/dir.txt

if [ -f "$destdir" ]
then
echo "$var" > "$destdir"
fi


echo "enter filter: "
read filter

./a.out $filter


