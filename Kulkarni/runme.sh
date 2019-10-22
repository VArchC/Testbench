#!/bin/bash
EXEC=kulkarni

NBITS="2 4 8 12 16"

for n in $NBITS; do
  ${VAC_CPU_MIPS_PATH}/mips.x -- ${EXEC}.${n}.mips 2>/dev/null &
  PID=$!
  wait ${PID}
  rm ${EXEC}.${n}.mips_varchc_counters_${PID}.csv
  rm ${EXEC}.${n}.mips_varchc_energy_${PID}.csv
done
