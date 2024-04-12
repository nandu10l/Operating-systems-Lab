echo "Enter a limit :"
read num
a=0
b=1 
echo "The Fibonacci series is : "
for (( i=0; i<num; i++ ))
do
    echo "$a "
    fn=$((a + b))
    a=$b
    b=$fn
done
