#!/bin/sh

#Setting the seeds
SEEDS=$(seq 500 50 1000)
INSTANCES=$(ls instances)

#BEST PARAMETERS BY ITERATED RACE
ANTS=9
ITERATIONS=80
RHO=0.5379

function regular {

mkdir output_regular

touch stat_regular.txt
echo "instance;seed;result" >> stat_regular.txt

for i in ${INSTANCES}; do
    for s in ${SEEDS}; do
        INSTID=$(echo ${i} | cut -d '.' -f 1)
        echo "running ${INSTID} ${s}"
        OUTFILE=output_regular/${i}_${s}.out
        ./ClosestringQt --file instances/${i} --seed ${s} --ants ${ANTS} --iterations ${ITERATIONS} --rho ${RHO} > ${OUTFILE}
        VALUE=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
        echo "${INSTID};${s};${VALUE}" >> stat_regular.txt
    done
done

}

function special {

mkdir output_special

touch stat_special.txt
echo "instance;seed;result" >> stat_special.txt

for i in ${INSTANCES}; do
    for s in ${SEEDS}; do
        INSTID=$(echo ${i} | cut -d '.' -f 1)
        echo "running ${INSTID} ${s}"
        OUTFILE=output_special/${i}_${s}.out
        ./ClosestringQt --file instances/${i} --seed ${s} --ants ${ANTS} --iterations ${ITERATIONS} --rho ${RHO} --elite --special > ${OUTFILE}
        VALUE=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
        echo "${INSTID};${s};${VALUE}" >> stat_special.txt
    done
done

}

function regularLocal {

mkdir output_regular_local

touch stat_regular_local.txt
echo "instance;seed;result" >> stat_regular_local.txt

for i in ${INSTANCES}; do
    for s in ${SEEDS}; do
        INSTID=$(echo ${i} | cut -d '.' -f 1)
        echo "running ${INSTID} ${s}"
        OUTFILE=output_regular_local/${i}_${s}.out
        ./ClosestringQt --file instances/${i} --seed ${s} --ants ${ANTS} --iterations ${ITERATIONS} --rho ${RHO} --local > ${OUTFILE}
        VALUE=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
        echo "${INSTID};${s};${VALUE}" >> stat_regular_local.txt
    done
done

}

function specialLocal {

mkdir output_special_local

touch stat_special_local.txt
echo "instance;seed;result" >> stat_special_local.txt

for i in ${INSTANCES}; do
    for s in ${SEEDS}; do
        INSTID=$(echo ${i} | cut -d '.' -f 1)
        echo "running ${INSTID} ${s}"
        OUTFILE=output_special_local/${i}_${s}.out
        ./ClosestringQt --file instances/${i} --seed ${s} --ants ${ANTS} --iterations ${ITERATIONS} --rho ${RHO} --elite --special > ${OUTFILE}
        VALUE=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
        echo "${INSTID};${s};${VALUE}" >> stat_special_local.txt
    done
done

}
