## Introduction

### Virtualizing the CPU
```
make cpu
./cpu A
./cpu A & ./cpu B & ./cpu C & ./cpu D &
```

### Virtualizing Memory
```
make mem
./mem 0
./mem 0 & ./mem 0 &
```

### Concurrency
```
make thread
./thread 1000
./thread 100000
```

### Persistence
```
make io
./io
cat /tmp/file
```
