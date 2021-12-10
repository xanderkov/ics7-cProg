POS=0
SUM_POS=0
NEG=0
SUM_NEG=0

for file in `ls func_tests`
do
	if [[ $file =~ pos_[0-9]{1}_in ]]
    then
        ((POS_SUM++))
        i=${file%_in}
        i=${i#pos_}
        ./`cat func_tests/pos_${i}_args` > output
        if cmp -s "output" "func_tests/pos_${i}_out"
        then
            ((POS++))
        else
            echo "Failed positive test $i. Program output:"
            cat output
            echo
        fi
    fi
    if [[ $file =~ neg_[0-7]{1}_in ]]
    then
        ((NEG_SUM++))
        i=${file%_in}
        i=${i#neg_}
        ./`cat func_tests/neg_${i}_args` > output
        if cmp -s "output" "func_tests/neg_${i}_out"
        then
            ((NEG++))
        else
            echo "Failed negative test $i."
            cat output
            echo
        fi
    fi
done

echo "Succeeded positives $POS/$POS_SUM"
echo "Succeeded negatives $NEG/$NEG_SUM"