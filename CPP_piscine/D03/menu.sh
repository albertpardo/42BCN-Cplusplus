NO_PRINT_DIR=--no-print-directory

echo "[Option list]"
echo
echo "0: Namespace "

echo

#read from keyboard
read -p "Select Option > " n
echo
#call the make program with the correct option
case $n in
	0) make $NO_PRINT_DIR poly;;

	*) echo "Invalid Option";;
esac
