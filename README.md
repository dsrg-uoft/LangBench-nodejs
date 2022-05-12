# LangBench Node.js 13.12.0 / V8 7.9.317.25 Instrumentation

## Building
Build instructions are same as Node.js. See README for original Node.js README.

## Instrumentation
In [deps/v8/src/krgc/krgc.cc](deps/v8/src/krgc/krgc.cc) edit `krgc::int_flag` and `krgc::jit_flag` to change instrumentation. See comments in that file for various options. All possible options can be viewed in [deps/v8/src/krgc/krgc.h](deps/v8/src/krgc/krgc.h).

Use the flag `-krgc_filter` to specify a comma separated list of function names to compile unsafe (what constitues unsafe is from the value of `krgc::jit_flag`). i.e. `node -krgc_filter=solve,partial_verify sudoku.js ../input-64.txt`

## Enabling permissions
```
sudo sh -c 'echo -1 >  /proc/sys/kernel/perf_event_paranoid'
sudo sh -c 'echo 2 > /sys/bus/event_source/devices/cpu/rdpmc'
```
