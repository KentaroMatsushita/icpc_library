# correct wrong generate
make $1
make $2
make $3
while true;do
./$3 > input.txt
c=$(./$1 < input.txt)
w=$(./$2 < input.txt)
if [[ $c = $w ]]; then
echo "pass"
else
echo "WA"
echo "$(cat input.txt)"
echo "o:"
echo "$c"
echo "x:"
echo "$w"
exit
fi
done