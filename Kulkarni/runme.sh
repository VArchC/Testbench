#!/bin/bash
EXEC=kulkarni

NBITS="2 4 8 12 16"

for n in $NBITS; do
  ${VAC_CPU_PATH}/${VAC_CPU}.x -- ${EXEC}.${n}.${VAC_CPU} 2>/dev/null &
  PID=$!
  wait ${PID}
  rm ${EXEC}.${n}.${VAC_CPU}_varchc_counters_${PID}.csv
  rm ${EXEC}.${n}.${VAC_CPU}_varchc_energy_${PID}.csv
done
