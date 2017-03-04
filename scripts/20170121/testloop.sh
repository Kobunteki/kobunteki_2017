#!/bin/bash

s=0
j=2

s=$j

echo $s

if [ -f testloop.sh ]; then
	echo wendi
else
	echo lily
fi

for i in `seq 100`
do 
	s=$(($s+$i)) #temp variable
done

echo $s

echo 'while loop\n'
m=0
i=0

while [ $i -le 10 ]
do
	m=$(($m + $i))
	i=$(($i+1))
done

echo $(($m/$(($i-1))))

for i in `seq 500`
do
	echo $i
	if [ $i -eq 30 ];then
		continue
	fi
	echo 'i love sherry'
done

for i in `cat testfile.txt`
do 
	if [[ $i =~ .conf$ ]];then
		echo $i	
	fi
done
