#!/bin/sh

#Setting the seeds
SEEDS=$(seq 500 50 1000)
INSTANCES=$(ls instances)
SMALLINST=$(ls smallinst)

#BEST PARAMETERS BY ITERATED RACE
ANTS=7
ITERATIONS=200
RHO=0.5044

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


#8   --ants 10 --iterations 600 --rho 0.9724
function specialLocal {

mkdir output_special_local

touch stat_special_local.txt
echo "instance;seed;result" >> stat_special_local.txt

for i in ${INSTANCES}; do
    for s in ${SEEDS}; do
        INSTID=$(echo ${i} | cut -d '.' -f 1)
        echo "running ${INSTID} ${s}"
        OUTFILE=output_special_local/${i}_${s}.out
        ./ClosestringQt --file instances/${i} --seed ${s} --ants 8 --iterations 800 --rho 0.9620 --elite  --local > ${OUTFILE}
        VALUE=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
        echo "${INSTID};${s};${VALUE}" >> stat_special_local.txt
    done
done
}

function convergence_regular {
    mkdir output_conv_regular
    touch stat_conv_regular.txt
    echo "instance;iterations;result;rpd" >> stat_conv_regular.txt
    ITERS=$(seq 100 100 1000)
    for s in ${SMALLINST}; do
        for i in ${ITERS}; do
            INSTID=$(echo ${s} | rev | cut -d '/' -f 1 | rev | cut -d '.' -f 1)
            OUTFILE=output_conv_regular/${s}_${i}.out
            ./ClosestringQt --file smallinst/${s} --rho 0.5044 --iterations ${i} --ants 7 > ${OUTFILE}
            RESULT=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 1)
            BEST=$(cat instances_opt.txt | grep ${s} | cut -d ';' -f 3)
            COST=$(echo "((${RESULT}-${BEST})/${BEST})*100" | bc -l)
            echo "${INSTID};${s};${RESULT};${COST}" >> stat_conv_regular.txt
        done
    done
}

function convergence_special {
    mkdir output_conv_special
    touch stat_conv_special.txt
    echo "instance;iterations;result;rpd" >> stat_conv_special.txt
    ITERS=$(seq 100 100 1000)
    for s in ${SMALLINST}; do
        for i in ${ITERS}; do
            INSTID=$(echo ${s} | rev | cut -d '/' -f 1 | rev | cut -d '.' -f 1)
            OUTFILE=output_conv_special/${s}_${i}.out
            ./ClosestringQt --file smallinst/${s} --rho 0.5044 --iterations ${i} --ants 7 --elite --special > ${OUTFILE}
            RESULT=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
            BEST=$(cat instances_opt.txt | grep ${s} | cut -d ';' -f 3)
            COST=$(echo "((${RESULT}-${BEST})/${BEST})*100" | bc -l)
            echo "${INSTID};${s};${RESULT};${COST}" >> stat_conv_special.txt
        done
    done
}

function convergence_local {
    mkdir output_conv_local
    touch stat_conv_local.txt
    echo "instance;iterations;result;rpd" >> stat_conv_local.txt
    ITERS=$(seq 100 100 1000)
    for s in ${SMALLINST}; do
        for i in ${ITERS}; do
            INSTID=$(echo ${s} | rev | cut -d '/' -f 1 | rev | cut -d '.' -f 1)
            OUTFILE=output_conv_local/${s}_${i}.out
            ./ClosestringQt --file smallinst/${s} --rho 0.5044 --iterations ${i} --ants 7 --elite --special --local > ${OUTFILE}
            RESULT=$(cat ${OUTFILE} | grep distance | cut -d ':' -f 2)
            BEST=$(cat instances_opt.txt | grep ${s} | cut -d ';' -f 3)
            COST=$(echo "((${RESULT}-${BEST})/${BEST})*100" | bc -l)
            echo "${INSTID};${s};${RESULT};${COST}" >> stat_conv_local.txt
        done
    done
}

