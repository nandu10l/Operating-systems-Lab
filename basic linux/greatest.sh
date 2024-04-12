
echo "Enter First number:"
read num1
echo "Enter second number:"
read num2
if((num1>num2))
then
	echo "$num1 is greater"
elif((num2>num1))
then
	echo "$num2 is greater"
else
	echo "both numbers are equal"		
fi	
