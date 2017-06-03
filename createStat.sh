#!/bin/sh

#Setting the seeds
SEEDS=$(seq 500 10 1000)
INSTANCES=$(ls instances)

#BEST PARAMETERS BY ITERATED RACE
ANTS=9
ITERATIONS=80
RHO=0.5379

function regular {

mkdir -f output_regular

touch stat_regular.txt
echo "instance;seed;result" >> stat_regular.txt

for i in ${INSTANCES}; do
    for s in ${SEEDS}; do
        OUTFILE=output_regular/${i}_${s}.out
        ./ClosestringQt --file {i} --ants ${ANTS} --iterations ${ITERATIONS} --rho ${RHO} > ${OUTFILE}
        VALUE=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
        echo "${i};${s};${VALUE}" >> stat_regular.txt
    done
done

}

function special {

mkdir -f output_special

touch stat_special.txt
echo "instance;seed;result" >> stat_special.txt

for i in ${INSTANCES}; do
    for s in ${SEEDS}; do
        OUTFILE=output_special/${i}_${s}.out
        ./ClosestringQt --file {i} --ants ${ANTS} --iterations ${ITERATIONS} --rho ${RHO} --elite --special > ${OUTFILE}
        VALUE=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
        echo "${i};${s};${VALUE}" >> stat_special.txt
    done
done

}

function regularLocal {

mkdir -f output_regular_local

touch stat_regular_local.txt
echo "instance;seed;result" >> stat_regular_local.txt

for i in ${INSTANCES}; do
    for s in ${SEEDS}; do
        OUTFILE=output_regular_local/${i}_${s}.out
        ./ClosestringQt --file {i} --ants ${ANTS} --iterations ${ITERATIONS} --rho ${RHO} --local > ${OUTFILE}
        VALUE=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
        echo "${i};${s};${VALUE}" >> stat_regular_local.txt
    done
done

}

function specialLocal {

mkdir -f output_special_local

touch stat_special_local.txt
echo "instance;seed;result" >> stat_special_local.txt

for i in ${INSTANCES}; do
    for s in ${SEEDS}; do
        OUTFILE=output_special_local/${i}_${s}.out
        ./ClosestringQt --file {i} --ants ${ANTS} --iterations ${ITERATIONS} --rho ${RHO} --elite --special > ${OUTFILE}
        VALUE=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
        echo "${i};${s};${VALUE}" >> stat_special_local.txt
    done
done

}
