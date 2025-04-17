NO_PRINT_DIR=--no-print-directory

echo "[Option list]"
echo
echo "0: c cast pointers"
echo "1: c cast pointers integer (Compile Error)"
echo "2: c++ Up Down cast (Compile error)"
echo "3: c++ Static cast (values)"
echo "4: c++ Static cast updowncast (Compile Error)"
echo "5: c++ Dynamic cast"
echo "6: c++ Reinterpret cast"
echo "7: c++ Constant cast (Compile error)"
echo "8: c++ Cast operators"
echo "9: c++ Explicit Keyword"
echo

#keread from keyboard
read -p "Select Option > " n
echo
#call the make program with the correct option
case $n in
	0) make $NO_PRINT_DIR cast2;;
	1) make $NO_PRINT_DIR cast3;;
	2) make $NO_PRINT_DIR updown;;
	3) make $NO_PRINT_DIR values;;
	4) make $NO_PRINT_DIR staticupdown;;
	5) make $NO_PRINT_DIR dynamic;;
	6) make $NO_PRINT_DIR reinterpret;;
	7) make $NO_PRINT_DIR constant;;
	8) make $NO_PRINT_DIR castoper;;
	9) make $NO_PRINT_DIR explicit;;
	*) echo "Invalid Option";;
esac
