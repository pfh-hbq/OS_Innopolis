touch file
echo 0 >> file

if ln file file.lock
then
	for (( i = 0; i < 50; i++ )); do
		k=$(tail -1 file)
		echo $(($k+1)) >> file
	done
	rm file.lock
fi