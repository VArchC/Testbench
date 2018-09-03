Kulkarni's approximated multiplier
==================================

This is a basic verification application for
[Kulkarni's approximated multiplier](https://ieeexplore.ieee.org/document/5718826/).

This application is written for the [VArchC MIPS32r2 CPU Model](https://github.com/VArchC/MIPS32r2).
To build it using GNU Make, set an environment variable *$VAC_CPU_MIPS_PATH* as the
path to the directory where the MIPS Model was build (e.g. the folder containing the *mips.x*
executable).
```bash
export VAC_CPU_MIPS_PATH=<path-to-MIPS32r2>
make
./runme.sh
```
