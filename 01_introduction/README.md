## Introduction

### Virtualizing the CPU
```
make cpu
./cpu.to A
./cpu.to A & ./cpu.to B & ./cpu.to C & ./cpu.to D &
```

### Virtualizing Memory
```
make mem
./mem.to 0
./mem.to 0 & ./mem.to 0 &
```

### Concurrency
```
make thread
./thread.to 1000
./thread.to 100000
```

### Persistence
```
make io
./io.to
cat /tmp/file
```
