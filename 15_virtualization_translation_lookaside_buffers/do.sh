PAGES=1
TRIALS=1000

for VARIABLE in {1..10}; do
    ./tlb.to $PAGES $TRIALS
    let "PAGES = $PAGES * 2"
done
