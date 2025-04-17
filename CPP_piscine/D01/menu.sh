NO_PRINT_DIR=--no-print-directory

echo "[Option list]"
echo

echo "0: New and delete "
echo "1: Student [42]"
echo "2: Reference 1"
echo "3: Reference 2"
echo "4: Reference 3"
echo "5: Filestreams 1"
echo

#read from keyboard
read -p "Select Option > " n
echo
#call the make program with the correct option
case $n in
	0) make $NO_PRINT_DIR newdelete;;
	1) make $NO_PRINT_DIR newdelarr;;
	2) make $NO_PRINT_DIR ref1;;
	3) make $NO_PRINT_DIR ref2;;
	4) make $NO_PRINT_DIR ref3;;
	5) make $NO_PRINT_DIR stream1;;

	*) echo "Invalid Option";;
esac
