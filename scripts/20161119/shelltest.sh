#!/bin/sh


echo 'Test1 begins' 

for file in *
do 
	if grep -q POSIX $file
	then
		echo $file
	fi
done


for foo in bar fud 53
do
	echo $foo
done

for foo in "bar fud 53"
do
	echo $foo
done

echo 'Enter password!'
read password

while [ "$password" != 'kobunteki loves sherry' ]
do
	echo 'Sorry, try again.'
	read password
done

until who | grep "$1" > /dev/null
do 
	sleep 60
done


echo -e '\a'

echo "******************$1 has just logged in*****************"

echo "Is it morning? Please answer yes or no"
read timeofday
case "$timeofday" in
	[Yy][Ee][Ss]) echo "Good Morning";;
	no)	 echo "Good Afternoon";;
	y)	 echo "Good Morning";;
	[nN]*)	 echo "Good Afternoon";;
	*)	 echo "Sorry, answer not recognized";;

esac

yes_or_no() {
	echo "Is your name $* ?"
	while true
	do 
		echo -n "Enter yes or no: "
		read x
		case "$x" in
			[Yy]|[Yy][Ee][Ss] ) return 0;;
			[Nn]|[Nn][Oo] ) return 1;;
			* )	echo "Answer yes or no"
		esac
	done
}

if yes_or_no "$1"
then 
	echo "Hi $1, nice name".
else
	echo "Never mind".
fi

trap 'rm -f /tmp/my_tmp_file_$$' INT
echo creating file /temp/my_tmp_file_$$
date > /tmp/my_tmp_file_$$

echo "press ctrl-c to interrupt ..."
while [ -f /tmp/my_tmp_file_$$ ]; do
	echo File exists
	sleep 1
done

echo The file no longer exists
#trap INT
echo creating file /temp/my_tmp_file_$$
date > /tmp/my_tmp_file_$$

while [ -f /tmp/my_tmp_file_$$ ]; do
	echo File exists
	sleep 1
done
echo we never get here

exit 0
