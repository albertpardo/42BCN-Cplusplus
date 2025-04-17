NO_PRINT_DIR=--no-print-directory

echo "[Option list]"
echo
echo "0: Namespace "
echo "1: TODOs"
echo "2: Canonical Form"
echo

#read from keyboard
read -p "Select Option > " n
echo
#call the make program with the correct option
case $n in
	0) make $NO_PRINT_DIR poly;;
	1) make $NO_PRINT_DIR io;;
	2) make $NO_PRINT_DIR canonical;;

	*) echo "Invalid Option";;
esac
