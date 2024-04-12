echo "Enter the first number :"
read num1
echo "Enter the second number :"
read num2
echo -e "1.add \n 2.subtract \n 3.multiply \n 4.divide"
echo "Enter choice"
read ch
case $ch in
1) echo "Sum of 2 numbers = $((num1+num2))";;
2) echo "difference of 2 numbers = $((num1-num2))";;
3) echo "Product of 2 numbers = $((num1*num2))";;
4) echo "Quotient of 2 numbers = $((num1/num2))";;
*) echo "Invalid choice";;
esac
