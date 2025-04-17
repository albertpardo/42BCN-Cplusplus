NO_PRINT_DIR=--no-print-directory

echo "[Option list]"
echo
echo "0: nsub-typing polymorphis"
echo "1: nsub-typing polymorphis with VIRTUAL"
echo "2: Abstrac and Interface"
echo

#read from keyboard
read -p "Select Option > " n
echo
#call the make program with the correct option
case $n in
	0) make $NO_PRINT_DIR poly;;
	1) make $NO_PRINT_DIR polyVir;;
	2) make $NO_PRINT_DIR poly2;;

	*) echo "Invalid Option";;
esac
