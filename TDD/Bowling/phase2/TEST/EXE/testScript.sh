#####################################################
#
# testScript.sh
#
# Script to run tests.
#
#####################################################
#echo "Running unit tests"

for i in ./TEST/EXE/runTest*
do
    echo "=========================="
    echo "Running $i"
    if test -f $i
    then
        if $VALGRIND ./$i 2>> TEST/EXE/tests.log
        then
            echo $i PASS
        else
            #echo "ERROR in test $i: here's TEST/EXE/tests.log"
            echo "ERROR in test $i"
            echo "------"
            #tail TEST/EXE/tests.log
            #exit 1
        fi
    fi
done

echo ""