NO_PRINT_DIR=--no-print-directory

echo "[Option list]"
echo
echo "0: Namespace "
echo "1: Stdio Streams"
echo "2: Class and instance"
echo "3: Member attributes and member function"
echo "4: This"
echo "5: Initialization list"
echo "6: Const"
echo "7: Visibility"
echo "8: Class vs struct"
echo "9: Accessors"
echo "10: Comparisons"
echo "11: Non member attributes and non member functions"
echo "12: Pointers to members"
echo

#read from keyboard
read -p "Select Option > " n
echo
#call the make program with the correct option
case $n in
	0) make $NO_PRINT_DIR namespace;;
	1) make $NO_PRINT_DIR io;;
	2) make $NO_PRINT_DIR sample_2;;
	3) make $NO_PRINT_DIR sample_3;;
	4) make $NO_PRINT_DIR this_4;;
	5) make $NO_PRINT_DIR initlist_5;;
	6) make $NO_PRINT_DIR const_6;;
	7) make $NO_PRINT_DIR visi_7;;
	8) make $NO_PRINT_DIR class_8;;
	9) make $NO_PRINT_DIR accessors_9;;
	10) make $NO_PRINT_DIR comparisons_10;;
	11) make $NO_PRINT_DIR non_11;;
	12) make $NO_PRINT_DIR point_12;;

	*) echo "Invalid Option";;
esac
