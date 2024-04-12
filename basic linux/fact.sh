echo "Enter a number :"
read num
fact=1
echo "Factorial is :"
for((i=1;i<=$num;i++))
do fact=$(($fact*$i))
done
echo "$fact"	
	
